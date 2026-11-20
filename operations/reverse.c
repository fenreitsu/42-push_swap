/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:16:32 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/20 19:49:28 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	do_reverse(t_stack *s)
{
	t_node	*prev;
	t_node	*last;

	if (!s || s->size < 2)
		return (0);
	prev = s->head;
	last = stack_get_last(s);
	while (prev->next != last)
	{
		prev = prev->next;
	}
	prev->next = NULL;
	last->next = s->head;
	s->head = last;
	return (1);
}

void	rra(t_stack *a, t_stats *stats)
{
	if (!do_reverse(a))
		return ;
	if (stats)
	{
		stats->rra++;
		stats->total++;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b, t_stats *stats)
{
	if (!do_reverse(b))
		return ;
	if (stats)
	{
		stats->rrb++;
		stats->total++;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, t_stats *stats)
{
	int	reversed_a;
	int	reversed_b;

	reversed_a = do_reverse(a);
	reversed_b = do_reverse(b);
	if (!reversed_a && !reversed_b)
		return ;
	if (stats)
	{
		stats->rrr++;
		stats->total++;
	}
	write(1, "rrr\n", 4);
}
