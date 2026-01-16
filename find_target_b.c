/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:51:28 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/16 18:12:39 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*min;
	t_stack	*current_node;
	int		size_stack;

	size_stack = ft_stack_size(stack);
	current_node = stack;
	min = current_node;
	while (size_stack--)
	{
		if (current_node->value < min->value)
			min = current_node;
		current_node = current_node->next;
	}
	return (min);
}

t_stack	*ft_get_smallest_big(int value, t_stack *stack)
{
	t_stack	*curr;
	int		size_stack;
	int		i;
	t_stack	*target;
	long	small_big;

	size_stack = ft_stack_size(stack);
	i = 0;
	curr = stack;
	target = NULL;
	small_big = 2147483648;
	while (i < size_stack)
	{
		if (value < curr->value && curr->value < small_big)
		{
			target = curr;
			small_big = curr->value;
		}
		i++;
		curr = curr->next;
	}
	return (target);
}

void	ft_find_target_b(t_stack **stack_a, t_stack **stack_b, int size_stack)
{
	t_stack	*curr_b;
	int		i;

	if (!(*stack_a) || !(*stack_b))
		return ;
	i = 0;
	curr_b = (*stack_b);
	while (i < size_stack)
	{
		curr_b->target_node = ft_get_smallest_big(curr_b->value, *stack_a);
		if (!curr_b->target_node)
			curr_b->target_node = ft_find_min(*stack_a);
		i++;
		curr_b = curr_b->next;
	}
	return ;
}
