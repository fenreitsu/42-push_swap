/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_medium.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 12:38:59 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/21 12:39:01 by reiascan         ###   ########.fr       */
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
	sort_medium(&a, &b, &stats);
	print_stacks(&a, &b, "RESULTADO DESPUES DE sort_medium");
	printf("sort_verifier -> %d (esperado: 1) | B->size: %d | ops total: %d\n",
		sort_verifier(&a), b.size, stats.total);
	stack_clear(&a);
	stack_clear(&b);
}

int	main(void)
{
	run_case((int []){5, 4, 3, 2, 1}, 5, "CASO n=5 INVERTIDO (chunk=3)");
	run_case((int []){40, -5, 100, -50, 2, 0, -1, 15, 77, -99}, 10,
		"CASO n=10 CON NEGATIVOS (chunk=3)");
	run_case((int []){18, 3, 25, 1, 14, 9, 30, 2, 21, 7, 12, 28, 5, 16, 11,
		24, 4, 19, 8, 15}, 20, "CASO n=20 VARIOS CHUNKS (chunk=15)");
	return (0);
}
