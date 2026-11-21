/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfavela- <rfavela-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 08:45:54 by rfavela-          #+#    #+#             */
/*   Updated: 2026/11/21 12:18:44 by rfavela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	process_chunk(t_stack *a, t_stack *b, t_stats *stats, int i)
{
	int		amount;

	if (i <= ((a->size) / 2))
	{
		amount = i;
		while (0 < amount)
		{
			ra(a, stats);
			amount--;
		}
		pb(a, b, stats);
	}
	else if (i > ((a->size) / 2))
	{
		amount = (a->size) - i;
		while (0 < amount)
		{
			rra(a, stats);
			amount--;
		}
		pb(a, b, stats);
	}

}

static void	push_chunks_to_b(t_stack *a, t_stack *b, t_stats *stats, int chunk_size)
{
	t_node	*numb;
	int		i;
	int		chunk_start;
	int		chunk_end;

	chunk_start = 0;
	chunk_end = chunk_size;
	while (a->size != 0)
	{
		i = 0;
		numb = a->head;
		while (i < a->size)
		{
			if (chunk_end > numb->index && numb->index >= chunk_start)
			{
				process_chunk(a, b, stats, i);
				if (numb->index <= ((chunk_size / 2) + chunk_start))
					rb(b, stats);
				i = 0;
				numb = a->head;
			}
			else
			{
				i++;
				numb = numb->next;
			}
		}
		chunk_start = chunk_start + chunk_size;
		chunk_end = chunk_end + chunk_size;
	}
}

void	sort_medium(t_stack *a, t_stack *b, t_stats *stats)
{
	int	chunk_size;

	chunk_size = sqrt(a->size);
	push_chunks_to_b(a, b, stats, chunk_size);
}