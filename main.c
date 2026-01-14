/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:52:14 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/14 14:58:52 by yorimek          ###   ########.fr       */
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
	printf("A et B initial\n");
	ft_print_stack_debug(stack_a);
	ft_print_stack_debug(stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
