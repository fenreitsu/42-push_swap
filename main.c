/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:50:33 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/22 17:33:11 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	get_strategy(t_stack *a, t_stack *b, t_stats *stats, t_config *cfg)
{
	if (cfg->strategy == SIMPLE)
		sort_simple(a, b, stats);
	if (cfg->strategy == MEDIUM)
		sort_medium(a, b, stats);
	if (cfg->strategy == COMPLEX)
		sort_complex(a, b, stats);
	if (cfg->strategy == ADAPTIVE)
		sort_adaptive(a, b, stats);
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_stats		stats;
	t_config	cfg;
	double		disorder;

	if (argc < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	ft_memset(&stats, 0, sizeof(t_stats));
	if (!(parse_args(argc, argv, &a, &cfg)))
	{
		stack_clear(&a);
		stack_clear(&b);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	disorder = compute_disorder(&a);
	if (a.size > 1 && !sort_verifier(&a))
		get_strategy(&a, &b, &stats, &cfg);
	print_bench(&stats, disorder, &cfg, a.size);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
