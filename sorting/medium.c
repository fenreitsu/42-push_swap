/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfavela- <rfavela-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 08:45:54 by rfavela-          #+#    #+#             */
/*   Updated: 2026/11/21 21:42:02 by rfavela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	process_chunkb(t_stack *a, t_stack *b, t_stats *stats, int i)
{
	int		amount;

	if (i <= ((b->size) / 2))
	{
		amount = i;
		while (0 < amount)
		{
			rb(b, stats);
			amount--;
		}
	}
	else if (i > ((b->size) / 2))
	{
		amount = (b->size) - i;
		while (0 < amount)
		{
			rrb(b, stats);
			amount--;
		}
	}
	pa(a, b, stats);
}

static void	push_back_to_a(t_stack *a, t_stack *b, t_stats *stats)
{
	t_node	*numb;
	int		i;
	int		find;

	find = b->size - 1;
	while (b->size != 0)
	{
		i = 0;
		numb = b->head;
		while (i < b->size)
		{
			if (numb->index == find)
			{
				process_chunkb(a, b, stats, i);
				i = 0;
				numb = b->head;
				continue ;
			}
			i++;
			numb = numb->next;
		}
		find --;
	}
}

static void	process_chunka(t_stack *a, t_stack *b, t_stats *stats, int i)
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
	}
	else if (i > ((a->size) / 2))
	{
		amount = (a->size) - i;
		while (0 < amount)
		{
			rra(a, stats);
			amount--;
		}
	}
	pb(a, b, stats);
}

static void	push_chunks_to_b(t_stack *a, t_stack *b,
	t_stats *stats, int chunk_size)
{
	t_node	*numb;
	int		i;
	int		end;

	end = chunk_size;
	while (a->size != 0)
	{
		i = 0;
		numb = a->head;
		while (i < a->size)
		{
			if (end > numb->index && numb->index >= (end - chunk_size))
			{
				process_chunka(a, b, stats, i);
				if (b->head->index <= ((chunk_size / 2) + (end - chunk_size)))
					rb(b, stats);
				i = 0;
				numb = a->head;
				continue ;
			}
			i++;
			numb = numb->next;
		}
		end = end + chunk_size;
	}
}

void	sort_medium(t_stack *a, t_stack *b, t_stats *stats)
{
	int	chunk_size;

	if (!a || !b || sort_verifier(a))
		return ;
	chunk_size = ft_sqrt(a->size);
	push_chunks_to_b(a, b, stats, chunk_size);
	push_back_to_a(a, b, stats);
}
