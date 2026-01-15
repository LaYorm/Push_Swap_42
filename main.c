/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:52:14 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/15 12:33:30 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    ft_print_stack_debug(t_stack *stack)
{
    t_stack *current;

    if (!stack)
    {
        printf("Stack is empty.\n");
        return ;
    }
    current = stack;
    printf("\n--- STACK DEBUG ---\n");
    while (1)
    {
        // 1. Position et Valeur
        printf("Pos: %2d | Val: %8d", current->index, current->value);

        // 2. Cible (Target)
        if (current->target_node != NULL)
            printf(" | Tgt: %8d", current->target_node->value);
        else
            printf(" | Tgt:     NONE");

        // 3. Médiane (Visualisation rapide)
        if (current->above_median)
            printf(" | Med: [ UP ]");
        else
            printf(" | Med: [DOWN]");

        // 4. Coûts
        printf(" | CostA: %2d | CostB: %2d", current->cost_a, current->cost_b);

        // 5. Liens (pour vérifier la circularité)
        printf(" | P: %8d | N: %8d\n",
            current->prev->value,
            current->next->value);

        current = current->next;
        if (current == stack)
            break ;
    }
    printf("-------------------\n\n");
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
	printf("----Size de A et B-------\n");
	printf("size_stack_a = %d\n", ft_stack_size(stack_a));
	printf("size_stack_b = %d\n", ft_stack_size(stack_b));
	ft_sorting_algo(&stack_a, &stack_b);
	printf("A et B apres algo\n");
	ft_print_stack_debug(stack_a);
	ft_print_stack_debug(stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
