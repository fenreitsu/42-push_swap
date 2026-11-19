#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

static void	print_stacks(t_stack *a, t_stack *b, const char *title)
{
	t_node	*curr_a;
	t_node	*curr_b;
	int		level;

	curr_a = a->head;
	curr_b = b->head;
	level = a->size;
	if (b->size > level)
		level = b->size;
	printf("\n=== %s ===\n", title);
	while (level > 0)
	{
		if (level <= a->size && curr_a)
		{
			printf("  %5d  ", curr_a->value);
			curr_a = curr_a->next;
		}
		else
			printf("         ");
		if (level <= b->size && curr_b)
		{
			printf("  %5d\n", curr_b->value);
			curr_b = curr_b->next;
		}
		else
			printf("       \n");
		level--;
	}
	printf("  -----    -----\n");
	printf("    A        B\n");
}

int	main(void)
{
	t_stack	a;
	t_stack	b;
	t_stats	stats;

	stack_init(&a);
	stack_init(&b);
	ft_memset(&stats, 0, sizeof(t_stats));
	stack_push_top(&a, stack_new_node(10));
	print_stacks(&a, &b, "ESTADO INICIAL (A solo tiene 1 valor)");
	printf("\nTry: sa con 1 elemento (NO debe imprimir nada):\n");
	sa(&a, &stats);
	stack_push_top(&a, stack_new_node(20));
	stack_push_top(&a, stack_new_node(30));
	stack_push_top(&b, stack_new_node(100));
	stack_push_top(&b, stack_new_node(200));
	print_stacks(&a, &b, "ANTES DE sa (30 y 20 arriba en A)");
	sa(&a, &stats);
	print_stacks(&a, &b, "DESPUES DE sa (20 y 30 intercambiados)");
	printf("\nTry: sb (200 y 100 arriba en B):\n");
	sb(&b, &stats);
	print_stacks(&a, &b, "DESPUES DE sb");
	printf("\nTry: ss (intercambia A y B a la vez):\n");
	ss(&a, &b, &stats);
	print_stacks(&a, &b, "DESPUES DE ss");
	printf("\nStats -> sa: %d | sb: %d | ss: %d | total: %d\n",
		stats.sa, stats.sb, stats.ss, stats.total);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
