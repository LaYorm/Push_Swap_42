/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:30:32 by yorimek           #+#    #+#             */
/*   Updated: 2026/01/13 11:03:28 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		full_len;
	char	*tab;
	int		i;
	int		j;

	full_len = ft_strlen(s1) + ft_strlen(s2);
	tab = malloc(sizeof(char) * (full_len + 2));
	if (!tab)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i++] = ' ';
	j = 0;
	while (s2[j])
	{
		tab[i + j] = s2[j];
		j++;
	}
	tab[i + j] = '\0';
	return (tab);
}

char	*ft_join_arg(int argc, char **argv)
{
	int		i;
	char	*temp;
	char	*tab;

	i = 1;
	tab = ft_strdup("");
	while (i < argc)
	{
		temp = tab;
		tab = ft_strjoin(temp, argv[i]);
		if (!tab)
			return (NULL);
		free (temp);
		i++;
	}
	return (tab);
}

char	*ft_strdup(char *str)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
