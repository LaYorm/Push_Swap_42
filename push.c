/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:56:51 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/16 18:42:51 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_after_extract(t_stack **stack)
{
	if ((*stack)->next == (*stack))
		(*stack) = NULL;
	else
	{
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->prev = (*stack)->prev;
		(*stack) = (*stack)->next;
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
	ft_set_after_extract(stack_b);
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
	write(1, "pa\n", 3);
	return ;
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_to_push;
	t_stack	*last_b;

	if (!(*stack_a))
		return ;
	node_to_push = (*stack_a);
	ft_set_after_extract(stack_a);
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
