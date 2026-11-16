/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:18:48 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/16 17:27:23 by reiascan         ###   ########.fr       */
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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
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
	write(1, "rr\n", 3);
}
