/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_from_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:47:57 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/16 18:10:22 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a) != (*stack_b)->target_node)
	{
		if ((*stack_b)->target_node->above_median)
			ft_rotate_a(stack_a);
		else if (!(*stack_b)->target_node->above_median)
			ft_reverse_rotate_a(stack_a);
	}
	ft_push_a(stack_a, stack_b);
}

void	ft_mv_cheapest(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	if (cheapest->above_median && cheapest->target_node->above_median)
	{
		while ((*stack_a) != cheapest && (*stack_b) != cheapest->target_node)
			ft_r_rotate(stack_a, stack_b);
	}
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
	{
		while ((*stack_a) != cheapest && (*stack_b) != cheapest->target_node)
			ft_r_reverse_rotate(stack_a, stack_b);
	}
	while ((*stack_a) != cheapest)
	{
		if (cheapest->above_median)
			ft_rotate_a(stack_a);
		else
			ft_reverse_rotate_a(stack_a);
	}
	while ((*stack_b) != cheapest->target_node)
	{
		if (cheapest->target_node->above_median)
			ft_rotate_b(stack_b);
		else
			ft_reverse_rotate_b(stack_b);
	}
	ft_push_b(stack_a, stack_b);
}
