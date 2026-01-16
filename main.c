/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:52:14 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/16 17:33:40 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    ft_print_stack_debug(t_stack *stack, char *name)
{
    t_stack *current;

    printf("\n--- STACK %s DEBUG (Size: %d) ---\n", name, ft_stack_size(stack));
    if (!stack)
    {
        printf("Stack is empty.\n");
        printf("---------------------------\n");
        return ;
    }
    current = stack;
    do
    {
        // Index et Valeur
        printf("Idx: %2d | Val: %10d", current->index, current->value);

        // Target (Cible)
        if (current->target_node)
            printf(" | Tgt: %10d", current->target_node->value);
        else
            printf(" | Tgt:       NULL");

        // Médiane
        printf(" | %s", current->above_median ? "[ UP ]" : "[DOWN]");

        // Coûts
        printf(" | CostA: %2d CostB: %2d", current->cost_a, current->cost_b);
        
        // Bonus: Marquer le moins cher si tu as le flag
        // if (current->cheapest) printf(" | <--- CHEAPEST");

        printf("\n");
        current = current->next;
    } while (current != stack);
    printf("---------------------------\n");
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    ft_get_stack_ready(argc, argv, &stack_a);
    // printf("\n=== ÉTAT INITIAL ===");
    // ft_print_stack_debug(stack_a, "A");
    // ft_print_stack_debug(stack_b, "B");
    ft_sorting_algo(&stack_a, &stack_b);
    // printf("\n=== RÉSULTAT FINAL ===");
    // ft_print_stack_debug(stack_a, "A");
    // ft_print_stack_debug(stack_b, "B");
    ft_free_stack(&stack_a);
    ft_free_stack(&stack_b);
    return (0);
}
