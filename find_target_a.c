/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:32:53 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/16 18:04:02 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_is_extrem(int value, t_stack *stack)
{
	t_stack	*max;
	t_stack	*min;
	t_stack	*current_node;
	int		size_stack;
	int		i;

	size_stack = ft_stack_size(stack);
	i = 0;
	max = stack;
	min = stack;
	current_node = stack;
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

t_stack	*ft_get_bigger_small(int value, t_stack *stack)
{
	t_stack	*curr;
	int		size_stack;
	int		i;
	t_stack	*target;
	long	big_small;

	size_stack = ft_stack_size(stack);
	i = 0;
	curr = stack;
	target = NULL;
	big_small = -2147483649;
	while (i < size_stack)
	{
		if (value > curr->value && curr->value > big_small)
		{
			target = curr;
			big_small = curr->value;
		}
		i++;
		curr = curr->next;
	}
	return (target);
}

void	ft_find_target_a(t_stack **stack_a, t_stack **stack_b, int size_stack)
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
	return ;
}
