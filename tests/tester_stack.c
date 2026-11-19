/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 15:38:03 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/14 15:38:04 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stack	a;
	t_node	*n1;
	t_node	*n2;

	stack_init(&a);
	n1 = malloc(sizeof(t_node));
	n2 = malloc(sizeof(t_node));
	n1->value = 42;
	n1->next = n2;
	n2->value = 10;
	n2->next = NULL;
	a.head = n1;
	a.size = 2;
	printf("Antes de clear: head=%d, size=%d\n", a.head->value, a.size);
	stack_clear(&a);
	printf("Despues de clear: head=%p, size=%d\n", (void *)a.head, a.size);
	return (0);
}
