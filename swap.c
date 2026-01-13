/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:02:59 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/13 11:55:37 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack *stack_a)
{
	int		temp_val;
	t_stack	*first;
	t_stack	*second;

	if (!stack_a || stack_a == stack_a->next)
		return ;
	first = stack_a;
	second = stack_a->next;
	temp_val = first->value;
	first->value = second->value;
	second->value = temp_val;
	return ;
}

void	ft_swap_b(t_stack *stack_b)
{
	int		temp_val;
	t_stack	*first;
	t_stack	*second;

	if (!stack_b || stack_b == stack_b->next)
		return ;
	first = stack_b;
	second = stack_b->next;
	temp_val = first->value;
	first->value = second->value;
	second->value = temp_val;
	return ;
}

void	ft_s_swap(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
	return ;
}
