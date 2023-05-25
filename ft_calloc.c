/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:34:56 by vlibert           #+#    #+#             */
/*   Updated: 2023/05/04 15:05:13 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	char	*s;
	size_t	x;

	x = nb * size;
	if (nb && x / nb != size)
		return (NULL);
	s = malloc(nb * size);
	if (!s)
		return (NULL);
	ft_bzero(s, nb * size);
	return (s);
}
