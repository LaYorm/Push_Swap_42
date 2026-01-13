/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:32:09 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/12 17:24:06 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_symbol(char *tab)
{
	int	i;

	i = 0;
	if (tab[i] == '+' || tab[i] == '-')
		i++;
	if (!tab[i])
		return (0);
	while (tab[i])
	{
		if (tab[i] < '0' || tab[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(char *tab)
{
	long	n;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	n = 0;
	if (tab[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (tab[i] == '+')
		i++;
	while (tab[i])
	{
		n = n * 10 + (tab[i] - '0');
		i++;
	}
	return (n * sign);
}

int	ft_is_duplicate(int n, t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (0);
	if (stack->value == n)
		return (1);
	current = stack->next;
	while (current != stack)
	{
		if (current->value == n)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_valid_char(char *tab)
{
	char	*res;

	res = tab;
	while (*tab)
	{
		if (*tab != '+' && *tab != '-' && !(*tab >= '0' && *tab <= '9')
			&& *tab != ' ')
		{
			free (res);
			write (2, "Error\n", 6);
			exit (1);
		}
		tab++;
	}
}
