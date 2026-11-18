/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 21:26:30 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/18 20:48:59 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_stack *a, t_stats *stats)
{
	int	first;
	int	second;
	int	third;

	if (!a || a->size != 3)
		return ;
	first = a->head->value;
	second = a->head->next->value;
	third = a->head->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, stats);
	// [ 3, 2, 1 ]
	else if (first > second && second > third && first > third)
	{
		sa(a, stats);
		rra(a, stats);
	}
	// [ 3, 1, 2 ]
	else if (first > second && second < third && first > third)
		ra(a, stats);
	// [ 1, 3, 2 ]
	else if (first < second && second > third && first < third)
	{
		sa(a, stats);
		ra(a, stats);
	}
	// [ 2, 3, 1 ]
	else if (first < second && second > third && first > third)
		rra(a, stats);
}

static void	push_min_to_b(t_stack *a, t_stack *b, t_stats *stats)
{
	int	min_pos;

	min_pos = get_min_pos(a);
	if (min_pos <= a->size / 2)
	{
		while (min_pos > 0)
		{
			ra(a, stats);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < a->size)
		{
			rra(a, stats);
			min_pos++;
		}
	}
	pb(a, b, stats);
}

void	sort_simple(t_stack *a, t_stack *b, t_stats *stats)
{
	if (!a || !b || sort_verifier(a))
		return ;
	if (a->size == 2)
	{
		sa(a, stats);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a, stats);
		return ;
	}
	while (a->size > 3 && sort_verifier(a) == 0)
		push_min_to_b(a, b, stats);
	sort_three(a, stats);
	while (b->size > 0 || b->head)
		pa(a, b, stats);
}
