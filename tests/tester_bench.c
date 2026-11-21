/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_bench.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 11:08:56 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/21 11:19:37 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

static void	fill_stats(t_stats *stats, int base)
{
	stats->pa = base;
	stats->pb = base;
	stats->sa = 1;
	stats->sb = 0;
	stats->ss = 0;
	stats->ra = base + 2;
	stats->rb = base - 1;
	stats->rr = 1;
	stats->rra = 2;
	stats->rrb = 1;
	stats->rrr = 0;
	stats->total = stats->pa + stats->pb + stats->sa + stats->sb + stats->ss
		+ stats->ra + stats->rb + stats->rr + stats->rra + stats->rrb
		+ stats->rrr;
}

static void	run_case(t_strategy strat, int bench_on, double disorder,
		const char *label)
{
	t_stats		stats;
	t_config	cfg;

	ft_memset(&stats, 0, sizeof(t_stats));
	fill_stats(&stats, 5);
	cfg.strategy = strat;
	cfg.bench = bench_on;
	printf("\n=== %s ===\n", label);
	fflush(stdout);
	print_bench(&stats, &cfg, disorder);
}

int	main(void)
{
	run_case(ADAPTATIVE, 0, 0.35, "CASO 1: BENCH APAGADO (no debe imprimir nada)");
	run_case(SIMPLE, 1, 0.1234, "CASO 2: SIMPLE (12.34%)");
	run_case(ADAPTATIVE, 1, 0.10, "CASO 3: ADAPTATIVE BAJO -> O(n^2)");
	run_case(ADAPTATIVE, 1, 0.35, "CASO 4: ADAPTATIVE MEDIO -> O(n*sqrt(n))");
	run_case(ADAPTATIVE, 1, 0.85, "CASO 5: ADAPTATIVE ALTO -> O(n log n)");
	return (0);
}
