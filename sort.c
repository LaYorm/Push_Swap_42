/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:13:13 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/15 13:52:17 by yorimek          ###   ########.fr       */
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

void	ft_sorting_algo(t_stack **stack_a, t_stack **stack_b)
{
	int	size_stack_a;
	int	size_stack_b;

	ft_push_b(stack_a, stack_b);
	ft_push_b(stack_a, stack_b);
	size_stack_a = ft_stack_size(*stack_a);
	while (size_stack_a > 3)
	{
		size_stack_b = ft_stack_size(*stack_b);
		ft_set_index(stack_a);
		ft_set_index(stack_b);
		ft_median(stack_a, size_stack_a);
		ft_median(stack_b, size_stack_b);
		ft_find_target(stack_a, stack_b, size_stack_a);
		ft_set_cost(stack_a, size_stack_a, size_stack_b);
		ft_find_move_cheapest(stack_a, stack_b, size_stack_a);
		size_stack_a = ft_stack_size(*stack_a);
	}
}
