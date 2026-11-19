/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_stack_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:38:05 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/14 22:34:34 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stack	a;
	t_node	*popped;

	stack_init(&a);
	stack_push_top(&a, stack_new_node(10));
	stack_push_top(&a, stack_new_node(20));
	stack_push_top(&a, stack_new_node(30));
	printf("Top: %d | Last: %d | Size: %d\n",
		a.head->value, stack_get_last(&a)->value, a.size);
	popped = stack_pop_top(&a);
	printf("Popped: %d | Nuevo Top: %d | Size: %d\n",
		popped->value, a.head->value, a.size);
	free(popped);
	stack_clear(&a);
	return (0);
}
