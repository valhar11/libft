/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:46:49 by vlibert           #+#    #+#             */
/*   Updated: 2023/05/11 15:46:50 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				result;
	unsigned char	search;

	search = (unsigned char) c;
	result = -1;
	i = 0;
	if (search == 0)
	{
		i = (int) ft_strlen(s);
		return ((char *) s + i);
	}
	while (s[i])
	{
		if (s[i] == search)
			result = i;
		i++;
	}
	if (result != -1)
		return ((char *)s + result);
	return (NULL);
}
