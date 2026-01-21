/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:13:13 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/21 12:01:53 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_already_sort(t_stack *stack_a)
{
	t_stack	*curr_node;

	curr_node = stack_a->next;
	while (curr_node != stack_a)
	{
		if (curr_node->value < curr_node->prev->value)
			return (1);
		curr_node = curr_node->next;
	}
	if (stack_a->value > stack_a->prev->value)
		return (1);
	return (0);
}

void	ft_bring_min_to_top(t_stack **stack_a)
{
	t_stack	*min;

	min = ft_find_min(*stack_a);
	while ((*stack_a) != min)
	{
		ft_set_index(stack_a);
		ft_median(stack_a, ft_stack_size(*stack_a));
		if (min->above_median)
			ft_rotate_a(stack_a);
		else if (!min->above_median)
			ft_reverse_rotate_a(stack_a);
	}
	return ;
}

int	ft_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_to_move;
	int		size_stack_a;
	int		size_stack_b;

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
	return (size_stack_a);
}

void	ft_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		size_stack_a;
	int		size_stack_b;

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
	return ;
}

void	ft_sorting_algo(t_stack **stack_a, t_stack **stack_b)
{
	int		size_stack_a;

	size_stack_a = ft_stack_size(*stack_a);
	if (!ft_is_already_sort(*stack_a))
		return ;
	if (ft_sort_small_pile(stack_a, size_stack_a))
		return ;
	size_stack_a = ft_a_to_b(stack_a, stack_b);
	ft_sort_small_pile(stack_a, size_stack_a);
	ft_b_to_a(stack_a, stack_b);
	ft_bring_min_to_top(stack_a);
	return ;
}
