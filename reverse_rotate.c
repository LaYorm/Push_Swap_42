/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:23:22 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/14 14:52:31 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	if (!(*stack) || (*stack) == (*stack)->next)
		return ;
	(*stack) = (*stack)->prev;
}

void	ft_reverse_rotate_a(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	write(1, "rra\n",4);
	return ;
}

void	ft_reverse_rotate_b(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
	write(1, "rrb\n",4);
	return ;
}

void	ft_r_reverse_rotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	return ;
}