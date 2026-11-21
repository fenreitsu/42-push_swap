/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 11:04:00 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/21 11:10:46 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Calculates the optimal chunk size based on total stack elements.
 *
 * Uses a square-root-scaled heuristic (~sqrt(size) * 1.5) to balance
 * rotations in stack A against search rotations in stack B.
 *
 * @param size Total number of elements in stack A.
 * @return int Target range width for each chunk pass.
 */
static int	get_chunk_size(int size)
{
	if (size <= 10)
		return (3);
	if (size <= 100)
		return (15);
	return (35);
}

/**
 * @brief Finds the zero-based position of the node with the highest index.
 *
 * @param b Pointer to stack B.
 * @return int Position from the top of stack B where the max index sits.
 */
static int	find_max_pos(t_stack *b)
{
	t_node	*curr;
	int		max_idx;
	int		max_pos;
	int		pos;

	curr = b->head;
	max_idx = -1;
	max_pos = 0;
	pos = 0;
	while (curr)
	{
		if (curr->index > max_idx)
		{
			max_idx = curr->index;
			max_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (max_pos);
}

/**
 * @brief Pushes all indexed elements from stack A to B in chunks.
 *
 * Elements within the sliding index window are pushed to B; elements
 * smaller than the current threshold are rotated to the bottom of B
 * to build an hourglass distribution.
 *
 * @param a Pointer to the primary stack.
 * @param b Pointer to the auxiliary stack.
 * @param stats Pointer to the operation counter structure.
 */
static void	push_chunks_to_b(t_stack *a, t_stack *b, t_stats *stats)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = get_chunk_size(a->size);
	while (a->size > 0)
	{
		if (a->head->index <= i)
		{
			pb(a, b, stats);
			rb(b, stats);
			i++;
		}
		else if (a->head->index <= i + chunk)
		{
			pb(a, b, stats);
			i++;
		}
		else
			ra(a, stats);
	}
}

/**
 * @brief Restores elements from stack B back to stack A in descending order.
 *
 * Repeatedly locates the maximum index in B, rotates it to the top via
 * the shortest path (rb or rrb), and pushes it onto A.
 *
 * @param a Pointer to the primary stack.
 * @param b Pointer to the auxiliary stack.
 * @param stats Pointer to the operation counter structure.
 */
static void	push_max_to_a(t_stack *a, t_stack *b, t_stats *stats)
{
	int	max_pos;

	while (b->size > 0)
	{
		max_pos = find_max_pos(b);
		if (max_pos <= b->size / 2)
		{
			while (max_pos-- > 0)
				rb(b, stats);
		}
		else
		{
			while (max_pos++ < b->size)
				rrb(b, stats);
		}
		pa(a, b, stats);
	}
}

/**
 * @brief Sorts a medium-sized or moderately disordered stack using Chunk Sort.
 *
 * Assigns zero-based indices, partitions elements into stack B in chunks,
 * and pushes them back to stack A from largest to smallest.
 *
 * @param a Pointer to the stack to be sorted.
 * @param b Pointer to the auxiliary stack.
 * @param stats Pointer to the structure recording executed operations.
 */
void	sort_medium(t_stack *a, t_stack *b, t_stats *stats)
{
	if (!a || !b || sort_verifier(a))
		return ;
	assign_index(a);
	push_chunks_to_b(a, b, stats);
	push_max_to_a(a, b, stats);
}
