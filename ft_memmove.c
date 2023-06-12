/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:36:41 by vlibert           #+#    #+#             */
/*   Updated: 2023/06/01 14:07:20 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memmove_n(unsigned char *t_dst, unsigned char *t_src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		t_dst[i] = t_src[i];
		i++;
	}
}

static void	ft_memmove_p(unsigned char *t_dst, unsigned char *t_src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		t_dst[len - 1] = t_src[len - 1];
		len--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*t_dst;
	unsigned char		*t_src;

	if (!dst && !src)
		return (NULL);
	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	if (t_dst < t_src)
		ft_memmove_n(t_dst, t_src, len);
	else
		ft_memmove_p(t_dst, t_src, len);
	return (dst);
}
