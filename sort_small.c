/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:26:55 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/19 11:27:14 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_max(t_stack *stack)
{
	t_stack	*max_node;
	int		i;
	int		max;

	if (!stack)
		return (NULL);
	max = stack->value;
	max_node = stack;
	i = 0;
	while (i < 3)
	{
		if (max < stack->value)
		{
			max_node = stack;
			max = stack->value;
		}
		i++;
		stack = stack->next;
	}
	return (max_node);
}

void	ft_sort_three(t_stack **stack_a)
{
	t_stack	*max;

	max = ft_find_max(*stack_a);
	if (*stack_a == max)
		ft_rotate_a(stack_a);
	if ((*stack_a)->next == max)
		ft_reverse_rotate_a(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		ft_swap_a(*stack_a);
	return ;
}

int	ft_sort_small_pile(t_stack **stack_a, int size)
{
	if (size <= 3)
	{
		if (size == 2 && (*stack_a)->value > (*stack_a)->next->value)
			ft_swap_a(*stack_a);
		else if (size == 3)
			ft_sort_three(stack_a);
		return (1);
	}
	return (0);
}
