/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 10:33:58 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/21 10:44:08 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_adaptive(t_stack *a, t_stack *b, t_stats *stats)
{
	double	disorder;

	if (!a || !b || sort_verifier(a))
		return ;
	disorder = compute_disorder(a);
	if (disorder < 0.2 || a->size <= 5)
		sort_simple(a, b, stats);
	else if (disorder >= 0.2 && disorder < 0.5)
		sort_medium(a, b, stats);
	else
		sort_complex(a, b, stats);
}
