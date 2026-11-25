/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:18:48 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/25 21:44:54 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	do_rotate(t_stack *s)
{
	t_node	*first;
	t_node	*last;

	if (!s || s->size < 2)
		return (0);
	first = stack_pop_top(s);
	last = stack_get_last(s);
	last->next = first;
	s->size++;
	return (1);
}

void	ra(t_stack *a, t_stats *stats)
{
	if (!do_rotate(a))
		return ;
	if (stats)
	{
		stats->ra++;
		stats->total++;
	}
	confirm_op_printer("ra\n", stats->silent_op);
}

void	rb(t_stack *b, t_stats *stats)
{
	if (!do_rotate(b))
		return ;
	if (stats)
	{
		stats->rb++;
		stats->total++;
	}
	confirm_op_printer("rb\n", stats->silent_op);
}

void	rr(t_stack *a, t_stack *b, t_stats *stats)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = do_rotate(a);
	rotated_b = do_rotate(b);
	if (!rotated_a && !rotated_b)
		return ;
	if (stats)
	{
		stats->rr++;
		stats->total++;
	}
	confirm_op_printer("rr\n", stats->silent_op);
}
