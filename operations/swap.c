/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 14:47:15 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/15 16:54:17 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// @brief Swaps the top two nodes of a stack without printing or updating stats
/// @param s Pointer to the stack to perform the swap on.
/// @return 1 if the swap was done, 0 if the stack==NULL || s->size < 2
static int	do_swap(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s || s->size < 2)
		return (0);
	first = s->head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	s->head = second;
	return (1);
}

void	sa(t_stack *a, t_stats *stats)
{
	if (!do_swap(a))
		return ;
	if (stats)
	{
		stats->sa++;
		stats->total++;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *b, t_stats *stats)
{
	if (!do_swap(b))
		return ;
	if (stats)
	{
		stats->sb++;
		stats->total++;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, t_stats *stats)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = do_swap(a);
	swapped_b = do_swap(b);
	if (!swapped_a && !swapped_b)
		return ;
	if (stats)
	{
		stats->ss++;
		stats->total++;
	}
	write(1, "ss\n", 3);
}
