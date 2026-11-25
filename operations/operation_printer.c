/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 20:56:34 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/25 21:57:06 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	confirm_op_printer(char *op, int confirm_op)
{
	if (!op || confirm_op)
		return ;
	ft_putstr_fd(op, 1);
}
