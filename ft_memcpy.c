/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:18:33 by vlibert           #+#    #+#             */
/*   Updated: 2023/05/08 13:03:50 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dst_temp;
	char	*src_temp;

	dst_temp = (char *) dest;
	src_temp = (char *) src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dst_temp[i] = src_temp[i];
		i++;
	}
	return (dst_temp);
}
