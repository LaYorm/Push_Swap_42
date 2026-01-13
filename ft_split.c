/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:33:36 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/12 11:52:13 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **tab, int lign)
{
	int	i;

	i = 0;
	while (i < lign)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_count_int(char *str)
{
	int	nb_int;
	int	i;
	int	in_int;

	nb_int = 0;
	in_int = 0;
	i = 0;
	while (str[i])
	{
		if (!in_int && str[i] != ' ')
		{
			nb_int++;
			in_int = 1;
		}
		if (in_int && str[i] == ' ')
			in_int = 0;
		i++;
	}
	return (nb_int);
}

void	ft_write_in_lign(char *tab, char *str, char sep, int *start_int)
{
	int	i;

	i = 0;
	while (str[*start_int] && str[*start_int] != sep)
	{
		tab[i] = str[*start_int];
		i++;
		(*start_int)++;
	}
	tab[i] = '\0';
}

int	ft_malloc_lign(char *str, char sep, char **tab, int nb_int)
{
	int	start_int;
	int	size_int;
	int	lign;

	lign = 0;
	start_int = 0;
	while (str[start_int] && lign < nb_int)
	{
		while (str[start_int] == sep)
			start_int++;
		size_int = 0;
		while (str[start_int + size_int] != sep && str[start_int + size_int])
			size_int++;
		tab[lign] = malloc(sizeof(char) * (size_int + 1));
		if (!tab[lign])
		{
			ft_free_split(tab, lign);
			return (0);
		}
		ft_write_in_lign(tab[lign], str, sep, &start_int);
		lign++;
	}
	tab[lign] = NULL;
	return (1);
}

char	**ft_split(char *str, char sep)
{
	char	**tab;
	int		nb_int;

	nb_int = ft_count_int(str);
	tab = malloc(sizeof(char *) * (nb_int + 1));
	if (!tab)
		return (NULL);
	if (!ft_malloc_lign(str, sep, tab, nb_int))
		return (NULL);
	return (tab);
}
