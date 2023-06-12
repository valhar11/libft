/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:22:27 by vlibert           #+#    #+#             */
/*   Updated: 2023/05/26 16:13:59 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == charset)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != charset)
				i++;
		}
	}
	return (count);
}

static int	split_len(const char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != charset)
		i++;
	return (i);
}

static int	ft_split_word(char **tab, const char *str, char charset, int count)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	j = 0;
	while (str[i] && nb < count)
	{
		j = 0;
		if (str[i] == charset)
			i++;
		if (str[i] && str[i] != charset && nb <= count)
		{
			tab[nb] = malloc(sizeof(char) * (split_len(str + i, charset) + 1));
			if (!tab[nb])
				return (1);
			while (str[i] && str[i] != charset)
				tab[nb][j++] = str[i++];
			tab[nb][j] = 0;
			nb++;
		}
	}
	tab[count] = 0;
	return (0);
}

char	**ft_split(char const *str, char charset)
{
	char	**tab;
	int		count;
	int		success;
	int		i;

	i = 0;
	success = 0;
	if (!str)
		return (NULL);
	count = ft_count_word(str, charset);
	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	if (count > 0)
		success = ft_split_word(tab, str, charset, count);
	if (success == 1)
	{
		while (tab[i] && i <= count)
			free(tab[i++]);
		free(tab);
		return (NULL);
	}
	tab[count] = 0;
	return (tab);
}
