/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:01:23 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/15 11:34:26 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	if (!(*stack) || (*stack) == (*stack)->next)
		return ;
	(*stack) = (*stack)->next;
	return ;
}

void	ft_rotate_a(t_stack **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
	return ;
}

void	ft_rotate_b(t_stack **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
	return ;
}

void	ft_r_rotate(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
	return ;
}
