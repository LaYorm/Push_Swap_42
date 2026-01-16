/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:49:09 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/16 15:12:40 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_cost_if_median(t_stack *curr_node)
{
	long	cost;

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

t_stack	*ft_find_cheapest(t_stack **stack_a, int size_a)
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
		cost = ft_cost_if_median(curr_node);
		if (cost < cheapest)
		{
			cheapest = cost;
			node_to_move = curr_node;
		}
		curr_node = curr_node->next;
	}
	return (node_to_move);
}
