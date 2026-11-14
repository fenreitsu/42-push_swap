/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:39:38 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/14 22:36:26 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*stack_new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	stack_push_top(t_stack *s, t_node *new_node)
{
	if (!s || !new_node)
		return ;
	new_node->next = s->head;
	s->head = new_node;
	s->size++;
}

t_node	*stack_pop_top(t_stack *s)
{
	t_node	*top_node;

	if (!s || !s->head)
		return (NULL);
	top_node = s->head;
	s->head = top_node->next;
	top_node->next = NULL;
	s->size--;
	return (top_node);
}

t_node	*stack_get_last(t_stack *s)
{
	t_node	*bottom_node;

	if (!s || !s->head)
		return (NULL);
	bottom_node = s->head;
	while (bottom_node->next)
	{
		bottom_node = bottom_node->next;
	}
	return (bottom_node);
}
