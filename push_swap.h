/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 22:29:54 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/14 22:34:29 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

void	stack_init(t_stack *s);
void	stack_clear(t_stack *s);
t_node	*stack_new_node(int value);
void	stack_push_top(t_stack *s, t_node *new_node);
t_node	*stack_pop_top(t_stack *s);
t_node	*stack_get_last(t_stack *s);

#endif
