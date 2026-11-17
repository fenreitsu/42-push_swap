/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfavela- <rfavela-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 21:55:41 by rfavela-          #+#    #+#             */
/*   Updated: 2026/11/16 20:53:54 by rfavela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	transfer_var(char **arr, t_stack *a)
{
	long	number;
	int		valid;
	int		len;
	t_node *new_node;

	if (arr == NULL || arr[0] == NULL)
		return (0);
	len = 0;
	while (arr[len] != NULL)
		len++;
	while (0 <= --len)
	{
		if (validate_syntax(arr[len]) == 0)
			return (0);
		number = ft_atol(arr[len]);
		if (number < -2147483648 || number > 2147483647)
			return (0);
		valid = number;
		new_node = stack_new_node(valid);
		if (new_node == NULL)
			return (0);
		stack_push_top(a, new_node);
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *a, t_config *cfg)
{
	int		i;
	char	**arr;

	i = 1;
	cfg->strategy = START;
	cfg->bench = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (match_flag(argv[i], cfg) == 0)
			return (0);
		i++;
	}
	if (cfg->strategy == START)
		cfg->strategy = ADAPTATIVE;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		if (arr == NULL)
			return (0);
		if (transfer_var(arr, a) == 0)
			return (free_arr(arr, 0));
		i++;
		free_arr(arr, 1);
	}
	return (1);
}
