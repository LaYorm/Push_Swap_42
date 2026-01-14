/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:02:59 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/14 14:54:35 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	int		temp_val;
	t_stack	*first;
	t_stack	*second;

	if (!stack || stack == stack->next)
		return ;
	first = stack;
	second = stack->next;
	temp_val = first->value;
	first->value = second->value;
	second->value = temp_val;
	return ;
}

void	ft_swap_a(t_stack *stack_a)
{
	ft_swap(stack_a);
	write(1,"sa\n", 3);
	return ;
}

void	ft_swap_b(t_stack *stack_b)
{
	ft_swap(stack_b);
	write(1,"sb\n", 3);
	return ;
}

void	ft_s_swap(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
	return ;
}
