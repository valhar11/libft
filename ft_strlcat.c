/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:54:55 by vlibert           #+#    #+#             */
/*   Updated: 2023/05/04 19:24:10 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	m;

	i = ft_strlen((const char *)dest);
	j = 0;
	while (src[j] && (j + i + 1) < dstsize)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (!src[j])
		dest[i + j] = 0;
	m = j;
	j = ft_strlen(src);
	if (dstsize == 0)
		return (j);
	if (i < dstsize)
	{
		dest[m + i] = 0;
		return (i + j);
	}
	return (dstsize + j);
}
