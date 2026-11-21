/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 11:30:17 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/21 13:32:55 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"	
#include "push_swap.h"

static void	print_disorder(double disorder)
{
	int	percent;

	percent = (int)((disorder * 10000) + 0.5);
	ft_putnbr_fd((percent / 100), 2);
	ft_putchar_fd('.', 2);
	if ((percent % 100) < 10)
		ft_putnbr_fd(0, 2);
	ft_putnbr_fd((percent % 100), 2);
	ft_putchar_fd('%', 2);
}

static const char	*get_strategy_label(t_strategy strategy, double disorder)
{
	if (strategy == SIMPLE)
		return ("Simple /  O(n^2)\n");
	if (strategy == MEDIUM)
		return ("Medium / O(n√n)\n");
	if (strategy == COMPLEX)
		return ("Complex / O(n log n)\n");
	if (strategy == ADAPTATIVE)
	{
		if (disorder < 0.2)
			return ("Adaptive / O(n^2)\n");
		if (disorder < 0.5)
			return ("Adaptive / O(n*sqrt(n))\n");
		else
			return ("Adaptive / O(n log n)\n");
	}
}

static void	print_ops(t_stats * stats)
{

}


void	print_bench(t_stats *stats, double disorder, t_config *cfg)
{
	if (!stats || !cfg || !cfg->bench)
		return ;
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder(disorder);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd((get_strategy_label(cfg->strategy, disorder)), 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(stats->total, 2);
	ft_putchar_fd('\n', 2);
	print_ops(stats);
}
