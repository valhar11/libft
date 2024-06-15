/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:45:49 by vlibert           #+#    #+#             */
/*   Updated: 2024/06/15 14:45:36 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_trim(char const *s1, char const *set)
{
	int		start;
	int		len;
	char	*dest;
	int		i;

	i = 0;
	start = 0;
	len = ft_strlen(s1) - 1;
	if (s1[0] != 0)
	{
		while (s1[start] && ft_ischarset(s1[start], (char *) set) == 1)
			start++;
		while (s1[len] && ft_ischarset(s1[len], (char *) set) == 1)
			len--;
	}
	if (len < start)
		return (dest = ft_calloc(1, sizeof(char)));
	dest = malloc(sizeof(char) * ((len - start) + 2));
	if (!dest)
		return (NULL);
	while (start <= len)
		dest[i++] = s1[start++];
	dest[i] = 0;
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	return (ft_trim(s1, set));
}
