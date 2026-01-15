/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:32:53 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/15 11:33:20 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_is_extrem(int value, t_stack *stack_b)
{
	t_stack	*max;
	t_stack	*min;
	t_stack	*current_node;
	int		size_stack;
	int		i;

	size_stack = ft_stack_size(stack_b);
	i = 0;
	max = stack_b;
	min = stack_b;
	current_node = stack_b;
	while (i < size_stack)
	{
		if (current_node->value > max->value)
			max = current_node;
		if (current_node->value < min->value)
			min = current_node;
		current_node = current_node->next;
		i++;
	}
	if (value < min->value || value > max->value)
	{
		return (max);
	}
	return (NULL);
}

t_stack	*ft_get_bigger_small(int value, t_stack *stack_b)
{
	t_stack	*curr_b;
	int		size_stack;
	int		i;
	t_stack	*target;
	long	big_small;

	size_stack = ft_stack_size(stack_b);
	i = 0;
	curr_b = stack_b;
	target = NULL;
	big_small = -2147483649;
	while (i < size_stack)
	{
		if (value > curr_b->value && curr_b->value > big_small)
		{
			target = curr_b;
			big_small = curr_b->value;
		}
		i++;
		curr_b = curr_b->next;
	}
	return (target);
}

void	ft_find_target(t_stack **stack_a, t_stack **stack_b, int size_stack)
{
	t_stack	*curr_a;
	t_stack	*extrem;
	int		i;

	if (!(*stack_a) || !(*stack_b))
		return ;
	i = 0;
	curr_a = (*stack_a);
	while (i < size_stack)
	{
		extrem = ft_is_extrem(curr_a->value, *stack_b);
		if (extrem)
			curr_a->target_node = extrem;
		else
			curr_a->target_node = ft_get_bigger_small(curr_a->value, *stack_b);
		i++;
		curr_a = curr_a->next;
	}
}
