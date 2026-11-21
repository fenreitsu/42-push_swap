/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfavela- <rfavela-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 21:42:31 by rfavela-          #+#    #+#             */
/*   Updated: 2026/11/21 22:04:23 by rfavela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include "libft/libft.h"


// int	main(int argc, char **argv)
// {
// 	t_config	cfg;
// 	t_stack		a;

// 	stack_init(&a);
// 	if (parse_args(argc, argv, &a, &cfg) == 0)
// 		error_exit();
// }

static void	run_test(int *values, int size, int test_num)
{
	t_stack	a;
	t_stack	b;
	t_stats	stats;
	t_node	*node;
	int		i;

	stack_init(&a);
	stack_init(&b);
	stats = (t_stats){0};
	i = size - 1;
	while (i >= 0)
	{
		node = stack_new_node(values[i]);
		stack_push_top(&a, node);
		i--;
	}
	assign_index(&a);
	printf("\n========== TEST %d ==========\n", test_num);
	printf("Size: %d\n", a.size);
	sort_medium(&a, &b, &stats);
	printf("Sorted: %s\n", sort_verifier(&a) ? "YES" : "NO");
	printf("Stack A size: %d\n", a.size);
	printf("Stack B size: %d\n", b.size);
	printf("Operations: %d\n", stats.total);
	stack_clear(&a);
	stack_clear(&b);
}

int	main(void)
{
	int	test1[] = {0};
	int	test2[] = {1, 0};
	int	test3[] = {2, 0, 1};
	int	test4[] = {0, 1, 2, 3, 4};
	int	test5[] = {4, 3, 2, 1, 0};
	int	test6[] = {7, 0, 6, 1, 5, 2, 4, 3};
	int	test7[] = {8, 0, 7, 1, 6, 2, 5, 3, 4};
	int	test8[] = {9, 0, 8, 1, 7, 2, 6, 3, 5, 4};

	run_test(test1, 1, 1);
	run_test(test2, 2, 2);
	run_test(test3, 3, 3);
	run_test(test4, 5, 4);
	run_test(test5, 5, 5);
	run_test(test6, 8, 6);
	run_test(test7, 9, 7);
	run_test(test8, 10, 8);
	return (0);
}

