/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_disorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 21:26:28 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/18 16:26:15 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	mistakes_counter(t_stack *a)
{
	t_node	*node;
	t_node	*next_node;
	int		mistakes;

	if (!a || a->size < 2)
		return (0);
	node = a->head;
	mistakes = 0;
	while (node != NULL)
	{
		next_node = node->next;
		while (next_node)
		{
			if (node->value > next_node->value)
				mistakes++;
			next_node = next_node->next;
		}
		node = node->next;
	}
	return (mistakes);
}

double	compute_disorder(t_stack *a)
{
	double	mistakes;
	double	total_pairs;
	double	size_stack;
	double	disorder;

	if (!a || a->size < 2)
		return (0);
	size_stack = a->size;
	total_pairs = (size_stack * (size_stack - 1)) / 2;
	mistakes = (double)mistakes_counter(a);
	disorder = mistakes / total_pairs;
	return (disorder);
}
