/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 18:24:05 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/18 18:39:44 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

static void	print_stack_nodes(t_stack *a, const char *title)
{
	t_node	*curr;
	int		pos;

	curr = a->head;
	pos = 0;
	printf("\n=== %s ===\n", title);
	while (curr)
	{
		printf("  [pos %d]  val: %5d  |  index: %2d\n",
			pos, curr->value, curr->index);
		curr = curr->next;
		pos++;
	}
	printf("  ---------------------------------\n");
}

int	main(void)
{
	t_stack	a;

	stack_init(&a);

	/* Desordenada con negativos [40, -5, 100, -50, 2] */
	stack_push_top(&a, stack_new_node(2));
	stack_push_top(&a, stack_new_node(-50));
	stack_push_top(&a, stack_new_node(100));
	stack_push_top(&a, stack_new_node(-5));
	stack_push_top(&a, stack_new_node(40));

	print_stack_nodes(&a, "ANTES DE assign_indexes");
	printf("sort_verifier    -> %d (esperado: 0)\n", sort_verifier(&a));
	printf("get_min_pos -> %d (esperado: 3 -> valor -50)\n", get_min_pos(&a));

	assign_index(&a);
	print_stack_nodes(&a, "DESPUES DE assign_indexes (idx: 3, 1, 4, 0, 2)");
	stack_clear(&a);

	/* Ya ordenada [-10, 0, 5, 20] */
	stack_push_top(&a, stack_new_node(20));
	stack_push_top(&a, stack_new_node(5));
	stack_push_top(&a, stack_new_node(0));
	stack_push_top(&a, stack_new_node(-10));

	print_stack_nodes(&a, "PILA ORDENADA: -10 0 5 20");
	printf("sort_verifier    -> %d (esperado: 1)\n", sort_verifier(&a));
	printf("get_min_pos -> %d (esperado: 0 -> valor -10)\n", get_min_pos(&a));
	stack_clear(&a);
	return (0);
}
