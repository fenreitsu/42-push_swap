/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfavela- <rfavela-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 21:55:41 by rfavela-          #+#    #+#             */
/*   Updated: 2026/11/19 20:52:40 by rfavela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	transfer_var(char **arr, t_stack *a)
{
	int		len;

	if (arr == NULL || arr[0] == NULL)
		return (0);
	len = 0;
	while (arr[len] != NULL)
		len++;
	while (0 <= --len)
	{
		if (validate_syntax(arr[len]) == 0)
			return (0);
		if (ft_atol(arr[len], a) == 0)
			return (0);
	}
	if (validate_duplicates(a) == 0)
		return (0);
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
			return (free_arr(arr, a, 0));
		if (transfer_var(arr, a) == 0)
			return (free_arr(arr, a, 0));
		free_arr(arr, a, 1);
		i++;
	}
	return (1);
}
