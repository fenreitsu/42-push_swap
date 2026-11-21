/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 19:35:07 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/21 11:21:50 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Calculates the maximum number of bits required to represent
 *        the largest zero-based index in the stack (size - 1).
 *
 * @param size Size of the stack (total number of elements in the stack).
 * @return int Maximum number of bit positions needed for Radix Sort,
 *             or 0 if size is less than or equal to 1.
 */
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

/**
 * @brief Executes a single bit-position pass of Radix Sort across stack A.
 *
 * Iterates through the initial elements of stack A: nodes whose index has a
 * 0 at @p bit_pos are pushed to stack B (pb), while nodes with a 1 are
 * rotated to the bottom of stack A (ra). Once all elements are processed,
 * stack B is pushed back onto stack A (pa).
 *
 * @param a Pointer to the primary stack containing indexed nodes.
 * @param b Pointer to the auxiliary stack used for temporary storage.
 * @param stats Pointer to the structure tracking operation counts.
 * @param bit_pos Zero-based bit index currently being evaluated.
 */
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

/**
 * @brief Sorts a large stack in ascending order using binary Radix Sort.
 *
 * Normalizes node values into zero-based indices and iteratively sorts
 * them from the least significant bit to the most significant bit until
 * the stack is completely ordered.
 *
 * @param a Pointer to the stack to be sorted.
 * @param b Pointer to the auxiliary stack.
 * @param stats Pointer to the structure recording executed operations.
 */
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
