/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 22:27:21 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/14 15:32:59 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_init(t_stack *s)
{
	if (!s)
		return ;
	s->head = NULL;
	s->size = 0;
}

void	stack_clear(t_stack *s)
{
	t_node	*current;
	t_node	*next_node;

	if (!s)
		return ;
	current = s->head;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	stack_init(s);
}
