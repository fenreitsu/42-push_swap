/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 22:29:54 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/21 11:11:05 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
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

typedef struct s_stats
{
	int	pa;
	int	pb;
	int sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
} t_stats;

void	stack_init(t_stack *s);
void	stack_clear(t_stack *s);
t_node	*stack_new_node(int value);
void	stack_push_top(t_stack *s, t_node *new_node);
t_node	*stack_pop_top(t_stack *s);
t_node	*stack_get_last(t_stack *s);
void	error_exit(void);
int		free_arr(char **arr, t_stack *a, int b);
int		match_flag(char *flag, t_config *cfg);
int		parse_args(int argc, char **argv, t_stack *a, t_config *cfg);
int		ft_atol(const char *nptr, t_stack *a);
int		validate_duplicates(t_stack *a);
int		validate_syntax(const char *str);
void	pa(t_stack *a, t_stack *b, t_stats *stats);
void	pb(t_stack *a, t_stack *b, t_stats *stats);
void	sa(t_stack *a, t_stats *stats);
void	sb(t_stack *b, t_stats *stats);
void	ss(t_stack *a, t_stack *b, t_stats *stats);
void	ra(t_stack *a, t_stats *stats);
void	rb(t_stack *b, t_stats *stats);
void	rr(t_stack *a, t_stack *b, t_stats *stats);
void	rra(t_stack *a, t_stats *stats);
void	rrb(t_stack *b, t_stats *stats);
void	rrr(t_stack *a, t_stack *b, t_stats *stats);
double	compute_disorder(t_stack *a);
int		sort_verifier(t_stack *a);
int		get_min_pos(t_stack *a);
void	assign_index(t_stack *a);
void	sort_simple(t_stack *a, t_stack *b, t_stats *stats);
void	sort_medium(t_stack *a, t_stack *b, t_stats *stats);
void	sort_complex(t_stack *a, t_stack *b, t_stats *stats);
void	sort_adaptive(t_stack *a, t_stack *b, t_stats *stats);

#endif
