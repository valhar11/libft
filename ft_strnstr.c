/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:13:11 by vlibert           #+#    #+#             */
/*   Updated: 2023/05/11 15:44:26 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (*needle == 0)
		return ((char *) str);
	while (str[i] && i < n)
	{
		j = 0;
		while ((i + j) < n && str[i + j] == needle[j])
		{
			j++;
			if (j == ft_strlen(needle))
				return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}
