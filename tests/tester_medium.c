/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_medium.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 15:01:02 by reiascan          #+#    #+#             */
/*   Updated: 2026/11/22 15:01:05 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

static void	print_stacks(t_stack *a, t_stack *b, const char *title)
{
	t_node	*curr_a;
	t_node	*curr_b;
	int		level;

	curr_a = a->head;
	curr_b = b->head;
	level = a->size;
	if (b->size > level)
		level = b->size;
	printf("\n--- %s ---\n", title);
	while (level > 0)
	{
		if (level <= a->size && curr_a)
		{
			printf("  %5d  ", curr_a->value);
			curr_a = curr_a->next;
		}
		else
			printf("         ");
		if (level <= b->size && curr_b)
		{
			printf("  %5d\n", curr_b->value);
			curr_b = curr_b->next;
		}
		else
			printf("       \n");
		level--;
	}
	printf("  -----    -----\n    A        B\n");
}

static void	fill_pseudo_random_100(int *arr)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		arr[i] = ((i * 37 + 13) % 100) - 50;
		i++;
	}
}

static void	run_case(int *arr, int n, int max_ops, const char *desc)
{
	t_stack	a;
	t_stack	b;
	t_stats	stats;
	int		i;

	stack_init(&a);
	stack_init(&b);
	ft_memset(&stats, 0, sizeof(t_stats));
	i = n - 1;
	while (i >= 0)
		stack_push_top(&a, stack_new_node(arr[i--]));
	printf("\n====================================================\n");
	printf("PRUEBA: %s\n", desc);
	printf("ESPERADO -> ft_sqrt(%d)=%d | A->size=%d | B->size=0 | sorted=1 | ops<=%d\n",
		n, ft_sqrt(n), n, max_ops);
	if (n <= 15)
		print_stacks(&a, &b, "ESTADO INICIAL");
	sort_medium(&a, &b, &stats);
	if (n <= 15)
		print_stacks(&a, &b, "ESTADO FINAL");
	printf("OBTENIDO -> A->size=%d | B->size=%d | sorted=%d | ops=%d\n",
		a.size, b.size, sort_verifier(&a), stats.total);
	if (a.size == n && b.size == 0 && sort_verifier(&a) == 1 && stats.total <= max_ops)
		printf("VEREDICTO: [PASS] Cumple logica y limite de operaciones\n");
	else
		printf("VEREDICTO: [FAIL] Fallo en ordenacion, tamano o exceso de ops\n");
	stack_clear(&a);
	stack_clear(&b);
}

int	main(void)
{
	int	arr100[100];

	run_case((int []){1, 2, 3, 4, 5}, 5, 0,
		"n=5 YA ORDENADA (debe cortar antes sin hacer movimientos)");
	run_case((int []){3, 1, 2}, 3, 5,
		"n=3 CHUNK PEQUENO (prueba ft_sqrt(3)=1 sin bucle infinito)");
	run_case((int []){5, 4, 3, 2, 1}, 5, 15,
		"n=5 INVERTIDA (ft_sqrt(5)=2 -> 3 chunks)");
	run_case((int []){40, -5, 100, -50, 2, 0, -1, 15, 77, -99}, 10, 45,
		"n=10 NEGATIVOS Y CERO (ft_sqrt(10)=3 -> prueba assign_index)");
	fill_pseudo_random_100(arr100);
	run_case(arr100, 100, 1500,
		"n=100 RENDIMIENTO CHUNKS (ft_sqrt(100)=10 -> limite subject <= 1500)");
	return (0);
}
