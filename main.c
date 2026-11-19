/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfavela- <rfavela-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 21:42:31 by rfavela-          #+#    #+#             */
/*   Updated: 2026/11/19 19:30:55 by rfavela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_config	cfg;
	t_stack		a;

	stack_init(&a);
	if (parse_args(argc, argv, &a, &cfg) == 0)
		error_exit();
}