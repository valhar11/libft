/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:10:29 by vlibert           #+#    #+#             */
/*   Updated: 2023/05/11 16:59:36 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *) str1;
	s2 = (unsigned char *) str2;
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((int) s1[i] - (int) s2[i]);
		i++;
	}
	return (0);
}
