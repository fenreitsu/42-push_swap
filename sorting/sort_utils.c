/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfavela- <rfavela-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 18:33:40 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/21 21:50:16 by rfavela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i * i) <= n)
		i++;
	return (i - 1);
}


int	sort_verifier(t_stack *a)
{
	t_node	*node;
	t_node	*next_node;

	if (!a || a->size < 2)
		return (1);
	node = a->head;
	next_node = node->next;
	while (node && next_node)
	{
		if (node->value < next_node->value)
			node = next_node;
		else
			return (0);
		next_node = next_node->next;
	}
	return (1);
}

int	get_min_pos(t_stack *a)
{
	t_node	*current;
	int		min_val;
	int		min_pos;
	int		actual_pos;

	if (!a || a->size < 2)
		return (0);
	current = a->head;
	min_val = current->value;
	actual_pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_pos = actual_pos;
		}
		current = current->next;
		actual_pos++;
	}
	return (min_pos);
}

/**
 * @brief Assigns a normalized rank index (0 to n - 1) to each node in stack A.
 *
 * Compares every node's value against all other nodes in the stack without
 * altering their positions, storing the count of strictly smaller elements
 * in node->index.
 *
 * @param a Pointer to the stack A.
*/
void	assign_index(t_stack *a)
{
	t_node	*current;
	t_node	*compare_node;
	int		counter;

	if (!a || a->size < 2)
		return ;
	current = a->head;
	while (current)
	{
		counter = 0;
		compare_node = a->head;
		while (compare_node)
		{
			if (compare_node->value < current->value)
				counter++;
			compare_node = compare_node->next;
		}
		current->index = counter;
		current = current->next;
	}
}
