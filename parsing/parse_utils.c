/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfavela- <rfavela-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 17:07:00 by rfavela-          #+#    #+#             */
/*   Updated: 2026/11/16 21:03:10 by rfavela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	int		i;
	long	number;
	long	sign;

	i = 0;
	sign = 1;
	number = 0;
	if (nptr[i] == 45)
	{
		sign *= -1;
		i++;
	}
	else if (nptr[i] == 43)
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		if (number < -LONG_MIN / 10 || number > LONG_MAX/10)
			return (0);
		number = (number * 10) + (nptr[i] - '0');
		i++;
	}
	return (number * sign);
}

static int	change_conf(t_config *cfg, t_strategy value)
{
	cfg->strategy = value;
	return (1);
}

int	match_flag(char *flag, t_config *cfg)
{
	int	flag_len;

	flag_len = ft_strlen(flag);
	if (cfg->strategy == START)
	{
		if ((flag_len == 8) && (ft_strncmp(flag, "--simple", flag_len)) == 0)
			return (change_conf(cfg, SIMPLE));
		if ((flag_len == 8) && (ft_strncmp(flag, "--medium", flag_len)) == 0)
			return (change_conf(cfg, MEDIUM));
		if ((flag_len == 9) && (ft_strncmp(flag, "--complex", flag_len)) == 0)
			return (change_conf(cfg, COMPLEX));
		if ((flag_len == 10) && (ft_strncmp(flag, "--adaptive", flag_len)) == 0)
			return (change_conf(cfg, ADAPTATIVE));
	}
	if ((flag_len == 7) && (ft_strncmp(flag, "--bench", flag_len)) == 0
		&& cfg->bench == 0)
	{
		cfg->bench = 1;
		return (1);
	}
	return (0);
}
int	free_arr(char **arr, int a)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return(a);
}