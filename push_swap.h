/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfavela- <rfavela-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 17:55:36 by rfavela-          #+#    #+#             */
/*   Updated: 2026/11/16 21:01:41 by rfavela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
typedef enum e_strategy
{
	START,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTATIVE,
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}	t_config;

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
