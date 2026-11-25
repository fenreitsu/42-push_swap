/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:33:16 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/25 21:44:59 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b, t_stats *stats)
{
	t_node	*node;

	if (!a || !b || !b->head)
		return ;
	node = stack_pop_top(b);
	stack_push_top(a, node);
	if (stats != NULL)
	{
		stats->pa++;
		stats->total++;
	}
	confirm_op_printer("pa\n", stats->silent_op);
}

void	pb(t_stack *a, t_stack *b, t_stats *stats)
{
	t_node	*node;

	if (!a || !b || !a->head)
		return ;
	node = stack_pop_top(a);
	stack_push_top(b, node);
	if (stats != NULL)
	{
		stats->pb++;
		stats->total++;
	}
	confirm_op_printer("pb\n", stats->silent_op);
}
