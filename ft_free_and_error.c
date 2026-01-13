/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:45:31 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/12 17:09:24 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*first;
	t_stack	*next_node;

	current = (*stack)->next;
	first = *stack;
	while (current != first)
	{
		next_node = current->next;
		free (current);
		current = next_node;
	}
	free(first);
}

void	ft_error(char **tab, t_stack **stack)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	if (stack && *stack)
		ft_free_stack(stack);
	write(2, "Error\n", 6);
	free (tab);
	exit (1);
}
