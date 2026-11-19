/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:07:41 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/16 17:08:06 by reiascan         ###   ########.fr       */
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

int	main(void)
{
	t_stack	a;
	t_stack	b;
	t_stats	stats;

	stack_init(&a);
	stack_init(&b);
	ft_memset(&stats, 0, sizeof(t_stats));
	stack_push_top(&a, stack_new_node(10));
	stack_push_top(&a, stack_new_node(20));
	stack_push_top(&a, stack_new_node(30));
	stack_push_top(&b, stack_new_node(100));
	stack_push_top(&b, stack_new_node(200));
	print_stacks(&a, &b, "ESTADO INICIAL");
	printf("\nEjecutando ra (30 baja al fondo de A):\n");
	ra(&a, &stats);
	print_stacks(&a, &b, "DESPUES DE ra");
	printf("\nEjecutando rb (200 baja al fondo de B):\n");
	rb(&b, &stats);
	print_stacks(&a, &b, "DESPUES DE rb");
	printf("\nEjecutando rr (rotan A y B a la vez):\n");
	rr(&a, &b, &stats);
	print_stacks(&a, &b, "DESPUES DE rr");
	printf("\nStats -> ra: %d | rb: %d | rr: %d | total: %d\n",
		stats.ra, stats.rb, stats.rr, stats.total);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
