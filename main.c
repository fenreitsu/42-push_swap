/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfavela- <rfavela-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 21:42:31 by rfavela-          #+#    #+#             */
/*   Updated: 2026/11/21 13:15:34 by rfavela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include "libft/libft.h"


// int	main(int argc, char **argv)
// {
// 	t_config	cfg;
// 	t_stack		a;

// 	stack_init(&a);
// 	if (parse_args(argc, argv, &a, &cfg) == 0)
// 		error_exit();
// }


static void	init_stack(t_stack *a, t_stack *b, t_stats *stats)
{
	int		i;
	int		values[5] = {5, 4, 3, 2, 1};
	t_node	*node;

	a->head = NULL;
	a->size = 0;
	b->head = NULL;
	b->size = 0;
	*stats = (t_stats){0};
	i = 0;
	while (i < 5)
	{
		node = malloc(sizeof(t_node));
		node->value = values[i];
		node->index = i;
		node->next = a->head;
		a->head = node;
		a->size++;
		i++;
	}
}

static void	print_stack(t_stack *s)
{
	t_node	*node;

	node = s->head;
	while (node)
	{
		printf("%d ", node->index);
		node = node->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	a;
	t_stack	b;
	t_stats	stats;

	init_stack(&a, &b, &stats);

	printf("BEFORE\nA: ");
	print_stack(&a);
	printf("B: ");
	print_stack(&b);

	printf("\n--- YOUR SORT_MEDIUM ---\n");
	sort_medium(&a, &b, &stats);

	printf("\nAFTER YOUR VERSION\nA: ");
	print_stack(&a);
	printf("B: ");
	print_stack(&b);

	return (0);
}

