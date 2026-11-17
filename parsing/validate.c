/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfavela- <rfavela-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:47:45 by rfavela-          #+#    #+#             */
/*   Updated: 2026/11/14 20:11:53 by rfavela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_syntax(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0' && (str[i] == 43 || str[i] == 45) && i < 1)
		i++;
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}
