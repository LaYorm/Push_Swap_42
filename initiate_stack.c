/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:20:28 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/13 11:03:20 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_to_stack(char **tab, t_stack **stack, int val)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		ft_error(tab, stack);
	new_node->value = val;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		last = (*stack)->prev;
		new_node->prev = last;
		new_node->next = *stack;
		(*stack)->prev = new_node;
		last->next = new_node;
	}
}

void	ft_tab_to_stack(char **tab, t_stack **stack_a)
{
	int		i;
	long	temp;

	i = 0;
	while (tab[i])
	{
		if (!ft_check_symbol(tab[i]))
			ft_error(tab, stack_a);
		temp = ft_atol(tab[i]);
		if (temp < INT_MIN || temp > INT_MAX)
			ft_error(tab, stack_a);
		if (ft_is_duplicate(temp, *stack_a))
			ft_error(tab, stack_a);
		ft_add_to_stack(tab, stack_a, (int)temp);
		i++;
	}
	ft_free_split(tab, i);
}

void	ft_get_stack_ready(int ac, char **av, t_stack **stack_a)
{
	char	*str_joined;
	char	**tab_split;

	str_joined = ft_join_arg(ac, av);
	if (!str_joined)
		exit (1);
	ft_valid_char(str_joined);
	tab_split = ft_split(str_joined, ' ');
	free(str_joined);
	if (!tab_split)
		exit (1);
	ft_tab_to_stack(tab_split, stack_a);
}
