/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:52:14 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/13 19:10:05 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print_stack_debug(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
	{
		printf("Stack is empty.\n");
		return ;
	}
	current = stack;
	printf("--- STACK DEBUG ---\n");
	while (1)
	{
		printf("Value: %d | Prev: %d | Next: %d\n",
			current->value,
			current->prev->value,
			current->next->value);
		current = current->next;
		if (current == stack)
			break ;
	}
	printf("-------------------\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	ft_get_stack_ready(argc, argv, &stack_a);
	//Print a et b
	printf("A et B initial\n");
	ft_print_stack_debug(stack_a);
	ft_print_stack_debug(stack_b);
	//Push 2 element de a dans b
	ft_push_b(&stack_a, &stack_b);
	//Reprint a et b	
	printf("\n\nApres 1 push de A dans B\n");
	ft_print_stack_debug(stack_a);
	ft_print_stack_debug(stack_b);
	//Swap 2 premier element de a et b
	ft_s_swap(stack_a, stack_b);
	//Reprint a et b
	printf("\n\nApres swap des 2 premiers elements de chaque stack\n");
	ft_print_stack_debug(stack_a);
	ft_print_stack_debug(stack_b);
	//Repush 1 seul element de b dans a
	ft_push_a(&stack_a, &stack_b);
	//Reprint a et b
	printf("\n\nApres 1 push de B dans A\n");
	ft_print_stack_debug(stack_a);
	ft_print_stack_debug(stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
