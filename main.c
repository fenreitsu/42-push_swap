/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfavela- <rfavela-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 21:42:31 by rfavela-          #+#    #+#             */
/*   Updated: 2026/11/19 20:18:06 by rfavela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int argc, char **argv)
// {
// 	t_config	cfg;
// 	t_stack		a;

// 	stack_init(&a);
// 	if (parse_args(argc, argv, &a, &cfg) == 0)
// 		error_exit();
// }

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_config	cfg;
	t_stack		a;
	t_node		*current;

	stack_init(&a);
	if (parse_args(argc, argv, &a, &cfg) == 0)
		error_exit();

	printf("\n--- PARSING RESULT ---\n");
	printf("Stack A size: %d\n", a.size);
	printf("Stack A values: ");

	current = a.head;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n---------------------\n");

	stack_clear(&a);
	return (0);
}
