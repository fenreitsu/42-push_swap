/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_disorder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:14:47 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/18 16:15:42 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

static void	print_stack_a(t_stack *a, const char *title)
{
	t_node	*curr;

	curr = a->head;
	printf("\n=== %s (size: %d) ===\n", title, a->size);
	while (curr)
	{
		printf("  %5d\n", curr->value);
		curr = curr->next;
	}
	printf("  -----\n");
	printf("    A  \n");
}

int	main(void)
{
	t_stack	a;

	stack_init(&a);
	printf("NULL               -> %.2f (esperado: 0.00)\n", compute_disorder(NULL));
	printf("Vacia (n=0)        -> %.2f (esperado: 0.00)\n", compute_disorder(&a));

	stack_push_top(&a, stack_new_node(42));
	print_stack_a(&a, "1 ELEMENTO: 42");
	printf("Disorder           -> %.2f (esperado: 0.00)\n", compute_disorder(&a));
	stack_clear(&a);

	// [1 2 3] -> ordenada
	stack_push_top(&a, stack_new_node(3));
	stack_push_top(&a, stack_new_node(2));
	stack_push_top(&a, stack_new_node(1));
	print_stack_a(&a, "ORDENADA: 1 2 3");
	printf("Disorder           -> %.2f (esperado: 0.00)\n", compute_disorder(&a));
	stack_clear(&a);

	// [2 1 3 6 5 8]
	stack_push_top(&a, stack_new_node(8));
	stack_push_top(&a, stack_new_node(5));
	stack_push_top(&a, stack_new_node(6));
	stack_push_top(&a, stack_new_node(3));
	stack_push_top(&a, stack_new_node(1));
	stack_push_top(&a, stack_new_node(2));
	print_stack_a(&a, "CASO SUBJECT: 2 1 3 6 5 8");
	printf("Disorder           -> %.2f (esperado: 0.13)\n", compute_disorder(&a));
	stack_clear(&a);

	// [1 3 2 5 4] -> limite 0.20
	stack_push_top(&a, stack_new_node(4));
	stack_push_top(&a, stack_new_node(5));
	stack_push_top(&a, stack_new_node(2));
	stack_push_top(&a, stack_new_node(3));
	stack_push_top(&a, stack_new_node(1));
	print_stack_a(&a, "LIMITE MEDIO: 1 3 2 5 4");
	printf("Disorder           -> %.2f (esperado: 0.20)\n", compute_disorder(&a));
	stack_clear(&a);

	// [5 4 3 2 1] -> invertida
	stack_push_top(&a, stack_new_node(1));
	stack_push_top(&a, stack_new_node(2));
	stack_push_top(&a, stack_new_node(3));
	stack_push_top(&a, stack_new_node(4));
	stack_push_top(&a, stack_new_node(5));
	print_stack_a(&a, "INVERTIDA: 5 4 3 2 1");
	printf("Disorder           -> %.2f (esperado: 1.00)\n", compute_disorder(&a));
	stack_clear(&a);
	return (0);
}
