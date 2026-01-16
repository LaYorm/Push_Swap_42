/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_for_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:39:25 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/16 15:40:15 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int		size_stack;
	t_stack	*current_node;

	if (!stack)
		return (0);
	size_stack = 1;
	current_node = stack->next;
	while (current_node != stack)
	{
		size_stack++;
		current_node = current_node->next;
	}
	return (size_stack);
}

void	ft_set_index(t_stack **stack)
{
	t_stack	*current_node;
	int		index;

	if (!(*stack))
		return ;
	current_node = (*stack)->next;
	index = 1;
	while (current_node != (*stack))
	{
		current_node->index = index;
		index++;
		current_node = current_node->next;
	}
	(*stack)->index = 0;
	return ;
}

void	ft_median(t_stack **stack, int size_stack)
{
	t_stack	*curr_node;
	int		median;

	if (!(*stack))
		return ;
	curr_node = (*stack);
	median = size_stack / 2;
	while (size_stack--)
	{
		if (curr_node->index <= median)
			curr_node->above_median = 1;
		else
			curr_node->above_median = 0;
		curr_node = curr_node->next;
	}
	return ;
}

void	ft_set_cost(t_stack **stack_a, int size_a, int size_b)
{
	t_stack	*curr_node;
	int		save_size_a;

	if (!(*stack_a))
		return ;
	curr_node = (*stack_a);
	save_size_a = size_a;
	while (size_a--)
	{
		if (curr_node->above_median)
			curr_node->cost_a = curr_node->index;
		if (!curr_node->above_median)
			curr_node->cost_a = save_size_a - curr_node->index;
		if (curr_node->target_node->above_median)
			curr_node->cost_b = curr_node->target_node->index;
		if (!curr_node->target_node->above_median)
			curr_node->cost_b = size_b - curr_node->target_node->index;
		curr_node = curr_node->next;
	}
	return ;
}
