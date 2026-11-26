*This project has been created as part of the 42 curriculum by reiascan and rfavela-.*

# push_swap

## Description

`push_swap` takes a list of integers and sorts them using only two stacks, named `a` and `b`, and a fixed set of instructions. It prints the instructions it performs, not the sorted list, and it aims to keep that list as short as possible.

Before moving any number, the program measures how disordered the input is and uses that value to choose a sorting method. The default mode makes that choice automatically.

Only the mandatory part of the subject is implemented. There is no checker source here.

---

## Allowed operations

| Instruction | Effect |
| :--- | :--- |
| `sa` | Swap the first two elements of `a`. |
| `sb` | Swap the first two elements of `b`. |
| `ss` | Swap the first two elements of both stacks. |
| `pa` | Move the top element of `b` to `a`. |
| `pb` | Move the top element of `a` to `b`. |
| `ra` | Rotate `a`: the first element becomes the last. |
| `rb` | Rotate `b`: the first element becomes the last. |
| `rr` | Rotate both stacks at once. |
| `rra` | Reverse rotate `a`: the last element becomes the first. |
| `rrb` | Reverse rotate `b`: the last element becomes the first. |
| `rrr` | Reverse rotate both stacks at once. |

`ss`, `rr` and `rrr` are printed as a single line and count as one operation.

---

## Disorder index

The index counts inverted pairs, that is, pairs where a larger number appears before a smaller one, and divides them by all possible pairs:

```
disorder = inverted pairs / total pairs
```

A sorted list gives `0.00%` and a reverse-sorted list gives `100.00%`. The value is computed once, before any instruction is emitted, and it is also reported by `--bench`.

Threshold justification: the `0.20` and `0.50` cut-offs are the ones defined by the 42 subject; we did not tune them to our own inputs. The index only counts inversions, so it cannot distinguish a reverse-sorted stack from a random one: a reverse-sorted stack has maximum disorder but is perfectly structured. In that case `sort_simple` finds the minimum at the bottom and needs one reverse rotation per extraction, so it performs close to linearly. On a random permutation the minimum is on average halfway down the stack, and the same scans reach the quadratic bound. Adaptive follows the subject cut-offs, so reversed input is sent to `complex`; this is a limitation of the metric, not a claim that `simple` is always worse.

---

## Strategies

### Simple — O(n²)

Algorithm: insertion by minimum.

What it does: keeps three numbers in `a`, repeatedly finds the smallest number in the rest, moves it to `b` with `ra`/`rra` and `pb`, orders those three numbers with `sa`, `ra` and `rra`, and finally brings everything in `b` back to `a` with `pa`.

When and why: used when the stack has five elements or fewer, or when disorder is below `0.20`. With so few elements, scanning for the minimum each time is cheap.

### Medium — O(n√n)

Algorithm: chunk sort.

What it does: assigns every value an index from `0` to `n - 1` with `assign_index`, sets `chunk_size = ft_sqrt(size)`, pushes each index range to `b`, rotates `b` when a value falls in the lower half of its chunk, and then pulls the values back to `a` from the largest index to the smallest.

When and why: used when disorder is between `0.20` and `0.50`. Part of the original order is still present, so grouping values is cheaper than looking for the minimum every time.

### Complex — O(n log n)

Algorithm: least-significant-bit binary radix sort.

What it does: computes how many bits are needed for the largest index and makes one pass per bit. During a pass, values with a `1` in the current bit rotate in `a` with `ra`, values with a `0` go to `b` with `pb`, and then every value in `b` returns to `a` with `pa`. When all bits have been processed, `a` is sorted.

When and why: used when disorder is `0.50` or more. A random input has no useful order to exploit, and radix gives a predictable number of passes.

### Adaptive (default)

Algorithm: selector driven by the disorder index.

What it does: the index is computed once in `main.c`. It calls `sort_simple` below `0.20` (or for at most five numbers), `sort_medium` between `0.20` and `0.50`, and `sort_complex` from `0.50` upwards.

When and why: this is the default mode. It avoids paying quadratic work on nearly sorted inputs and chunk work on random ones.

---

## Instructions

### Build

```
make            # builds ./push_swap
make clean      # removes object files
make fclean     # removes object files and the binary
make re         # fclean followed by make
```

The Makefile compiles with `cc -Wall -Wextra -Werror -I . -I libft`. It builds `libft` from its own Makefile before linking `push_swap`.

### Usage

```
./push_swap 3 2 1
./push_swap "3 2 1"
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
./push_swap --bench --simple 2 1
```

Numbers can be given as separate arguments or inside one quoted argument. Strategy flags and `--bench` must appear before the numbers; without a strategy flag the program behaves like `--adaptive`. With no arguments it prints nothing and exits. Invalid numbers, duplicates and values outside `int` print `Error` on `stderr` and exit with status `1`. An input that is already sorted produces no instructions.

Instructions are written to `stdout`, one per line.

```
ARG="3 2 1"; ./push_swap $ARG
```

### Benchmark mode

`--bench` writes metrics to `stderr` while the instructions keep going to `stdout`:

```
$ ./push_swap --bench --simple 2 1 >/dev/null
[bench] disorder: 100.00%
[bench] strategy: Simple / O(n^2)
[bench] total_ops: 1
[bench] sa: 1  sb: 0  ss: 0  pa: 0  pb: 0
[bench] ra: 0  rb: 0  rr: 0  rra: 0  rrb: 0  rrr: 0
```

The report shows the initial disorder, the strategy with its complexity class, the total number of operations and a count for each instruction.

---

## Complexity analysis

Time is counted as the number of emitted `push_swap` operations, which is the metric used by the subject, not CPU time. The two stacks already hold `n` nodes, so total space is `O(n)`; extra space on top of them is `O(1)` because indices are stored inside each node. `Simple` has an `O(n²)` upper bound for arbitrary input, but on reverse-sorted input it is close to `O(n)` because the minimum is always at the bottom. `complex` stays near `O(n log n)` regardless of order.

| Method | Time | Auxiliary space |
| :--- | :--- | :--- |
| Simple | O(n²) | O(1) beyond the node lists |
| Medium | O(n√n) | O(1) beyond the node lists |
| Complex | O(n log n) | O(1) beyond the node lists |
| Adaptive | O(n²) worst case | O(1) beyond the node lists |

All methods work on the same linked stacks. Normalised indices are stored in each node, so no extra array is needed during sorting.

---

## Design notes

Both stacks are passed by pointer, so called functions modify the original lists instead of copies. Each operation checks for an empty stack before touching it.

The eleven operation functions update one `t_stats` structure and delegate printing to `confirm_op_printer`, which keeps the benchmark counters in sync with the printed instructions.

---

## Project structure

```
.
├── main.c          strategy dispatch and program flow
├── bench.c         benchmark output
├── push_swap.h     types, prototypes and strategy enum
├── Makefile        builds the binary and libft
├── parsing/        flags, argument splitting and validation
├── stack/          node creation, push/pop and cleanup
├── operations/     the eleven instructions and their printer
├── sorting/        simple, medium, complex, adaptive and helpers
├── libft/          local library linked by the Makefile
├── tests/          Our tests for each function we wrote as we went along.
└── push_swap       compiled executable
```

---

## Contributions

| Area | reiascan | rfavela- |
| :--- | :---: | :---: |
| `main.c` | ✔ | ✔ |
| `push_swap.h` | ✔ | ✔ |
| Parsing | | ✔ |
| Stacks | ✔ | |
| Operations | ✔ | |
| `sorting` | ✔ | |
| `sorting/medium.c` | | ✔ |
| Bench | ✔ | |


---

## Troubleshooting

To check for memory leaks with the same input used to sort:

```
valgrind ./push_swap 3 2 1
```

---

## Resources

### References and Inspirations

* **42 subject PDF** – Contains the project's specific rules, exact prototypes, norm requirements, and evaluation criteria.
* **Radix sort algorithm introduction with a simple example:**\
 [![Ver video](https://img.youtube.com/vi/XiuSW_mEn7g/maxresdefault.jpg)](https://www.youtube.com/watch?v=XiuSW_mEn7g)
* **Oceano - Push_Swap:** \
[![Ver video](https://i.ytimg.com/vi/OaG81sDEpVk/hqdefault.jpg)](https://www.youtube.com/watch?v=OaG81sDEpVk)

* **Thuggonaut - Push-swap:** \
[![Ver video](https://img.youtube.com/vi/wRvipSG4Mmk/maxresdefault.jpg)](https://www.youtube.com/watch?v=wRvipSG4Mmk)

### Herramientas de prueba

* **Our Tests** – Our tests, although simple, were the ones that helped us raise most of the problems and/or figure out how to approach our functions.
* **https://pythontutor.com/c.html** – A step-by-step C code visualization tool. It was used to identify bugs, understand the execution flow, and debug pointer handling.

### Use of AI

AI was used solely to write and format these README files and for the structural organization of the project.
