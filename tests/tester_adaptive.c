/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_adaptive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 10:46:11 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/21 11:20:18 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	run_case(int *arr, int n, const char *label)
{
	t_stack	a;
	t_stack	b;
	t_stats	stats;
	int		i;

	stack_init(&a);
	stack_init(&b);
	ft_memset(&stats, 0, sizeof(t_stats));
	i = n - 1;
	while (i >= 0)
	{
		stack_push_top(&a, stack_new_node(arr[i]));
		i--;
	}
	print_stacks(&a, &b, label);
	printf("disorder inicial -> %.2f\n", compute_disorder(&a));
	sort_adaptive(&a, &b, &stats);
	print_stacks(&a, &b, "RESULTADO DESPUES DE sort_adaptive");
	printf("sort_verifier -> %d (esperado: 1) | B->size: %d | ops total: %d\n",
		sort_verifier(&a), b.size, stats.total);
	stack_clear(&a);
	stack_clear(&b);
}

int	main(void)
{
	run_case((int []){1, 2, 3, 4, 5, 6, 7, 8}, 8,
		"CASO 1: YA ORDENADA (disorder = 0.00)");
	run_case((int []){1, 2, 3, 4, 5, 6, 8, 7}, 8,
		"CASO 2: DESORDEN BAJO (< 0.2 -> sort_simple)");
	run_case((int []){4, 3, 2, 1, 5, 6, 7, 8}, 8,
		"CASO 3: DESORDEN MEDIO (0.2 - 0.5 -> sort_medium)");
	run_case((int []){8, 7, 6, 5, 4, 3, 2, 1}, 8,
		"CASO 4: DESORDEN ALTO (>= 0.5 -> sort_complex)");
	return (0);
}
