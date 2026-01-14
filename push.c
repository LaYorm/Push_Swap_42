/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:56:51 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/14 14:58:32 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_b_after_extract(t_stack **stack_b)
{
	if ((*stack_b)->next == (*stack_b))
		(*stack_b) = NULL;
	else
	{
		(*stack_b)->prev->next = (*stack_b)->next;
		(*stack_b)->next->prev = (*stack_b)->prev;
		(*stack_b) = (*stack_b)->next;
	}
	return ;
}

void	ft_set_a_after_extract(t_stack **stack_a)
{
	if ((*stack_a)->next == (*stack_a))
		(*stack_a) = NULL;
	else
	{
		(*stack_a)->prev->next = (*stack_a)->next;
		(*stack_a)->next->prev = (*stack_a)->prev;
		(*stack_a) = (*stack_a)->next;
	}
	return ;
}

void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last_a;
	t_stack	*node_to_push;

	if (!*stack_b)
		return ;
	node_to_push = *stack_b;
	ft_set_b_after_extract(stack_b);
	if (!(*stack_a))
	{
		node_to_push->next = node_to_push;
		node_to_push->prev = node_to_push;
	}
	else
	{
		last_a = (*stack_a)->prev;
		node_to_push->next = (*stack_a);
		node_to_push->prev = last_a;
		(*stack_a)->prev = node_to_push;
		last_a->next = node_to_push;
	}
	(*stack_a) = node_to_push;
	write(1, "pa\n", 1);
	return ;
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_to_push;
	t_stack	*last_b;

	if (!(*stack_a))
		return ;
	node_to_push = (*stack_a);
	ft_set_a_after_extract(stack_a);
	if (!(*stack_b))
	{
		node_to_push->next = node_to_push;
		node_to_push->prev = node_to_push;
	}
	else
	{
		last_b = (*stack_b)->prev;
		(*stack_b)->prev = node_to_push;
		node_to_push->prev = last_b;
		node_to_push->next = (*stack_b);
		last_b->next = node_to_push;
	}
	(*stack_b) = node_to_push;
	write(1, "pb\n", 3);
	return ;
}
