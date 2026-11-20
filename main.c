/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:50:33 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/20 19:04:59 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	parse_args(int argc, char **argv, t_stack *a, t_config *cfg);

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	cfg;
	t_stats		stats;

	if (argc < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	ft_memset(&stats, 0, sizeof(t_stats));
	if (!parse_args(argc, argv, &a, &cfg))
	{
		stack_clear(&a);
		stack_clear(&b);
		write(2, "Error\n", 6);
		return (1);
	}
	if (a.size > 1 && !sort_verifier(&a))
		sort_simple(&a, &b, &stats);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
