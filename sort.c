/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:13:13 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/16 18:44:04 by yorimek          ###   ########.fr       */
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

void	ft_sorting_algo(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_to_move;
	int		size_stack_a;
	int		size_stack_b;

	size_stack_a = ft_stack_size(*stack_a);
	if (ft_sort_small_pile(stack_a, size_stack_a))
		return ;
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
		ft_find_target_a(stack_a, stack_b, size_stack_a);
		ft_set_cost(stack_a, size_stack_a, size_stack_b);
		node_to_move = ft_find_cheapest(stack_a, size_stack_a);
		ft_mv_cheapest(stack_a, stack_b, node_to_move);
		size_stack_a = ft_stack_size(*stack_a);
	}
	ft_sort_small_pile(stack_a, size_stack_a);
	while ((*stack_b))
	{
		size_stack_a = ft_stack_size(*stack_a);
		size_stack_b = ft_stack_size(*stack_b);
		ft_set_index(stack_a);
		ft_set_index(stack_b);
		ft_median(stack_a, size_stack_a);
		ft_median(stack_b, size_stack_b);
		ft_find_target_b(stack_a, stack_b, size_stack_b);
		ft_move_to_a(stack_a, stack_b);
	}
	
}
