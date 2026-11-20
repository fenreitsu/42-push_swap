/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 19:35:07 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/20 21:19:48 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_max_bits(int size)
{
	int	max_num;
	int	max_bits;

	max_num = size - 1;
	max_bits = 0;
	if (size <= 1)
		return (max_bits);
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	sort_bit_pass(t_stack *a, t_stack *b, t_stats *stats, int bit_pos)
{
	int	counter;
	int	size;
	int	top_index;

	counter = 0;
	size = a->size;
	while (counter < size)
	{
		top_index = a->head->index;
		if (((top_index >> bit_pos) & 1) == 1)
			ra(a, stats);
		else
			pb(a, b, stats);
		counter++;
	}
	while (b->size > 0)
		pa(a, b, stats);
}

void	sort_complex(t_stack *a, t_stack *b, t_stats *stats)
{
	int	max_bits;
	int	bit_pos;

	if (!a || !b || sort_verifier(a))
		return ;
	assign_index(a);
	max_bits = get_max_bits(a->size);
	bit_pos = 0;
	while (bit_pos < max_bits && !sort_verifier(a))
	{
		sort_bit_pass(a, b, stats, bit_pos);
		bit_pos++;
	}
}
