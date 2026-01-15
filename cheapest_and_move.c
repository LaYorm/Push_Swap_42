/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_and_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:49:09 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/15 13:49:28 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_cost_if_median(t_stack **stack_a, t_stack *curr_node, long cost)
{
	if (curr_node->above_median == curr_node->target_node->above_median)
	{
		if (curr_node->cost_a > curr_node->cost_b)
			cost = curr_node->cost_a;
		else
			cost = curr_node->cost_b;
	}
	else
		cost = curr_node->cost_a + curr_node->cost_b;
	return (cost);
}

void	ft_find_move_cheapest(t_stack **stack_a, t_stack **stack_b, int size_a)
{
	t_stack	*curr_node;
	t_stack	*node_to_move;
	long	cost;
	long	cheapest;

	curr_node = (*stack_a);
	node_to_move = curr_node;
	cost = curr_node->cost_a + curr_node->cost_b;
	cheapest = cost;
	while (size_a--)
	{
		cost = ft_cost_if_median(stack_a, curr_node, cost);
		if (cost < cheapest)
		{
			cheapest = cost;
			node_to_move = curr_node;
		}
		curr_node = curr_node->next;
	}
	ft_move_cheapest(node_to_move, stack_a, stack_b);
	return ;
}
