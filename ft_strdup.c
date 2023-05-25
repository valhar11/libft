/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:46:34 by vlibert           #+#    #+#             */
/*   Updated: 2023/05/11 15:48:49 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*cp;

	i = 0;
	len = ft_strlen(s);
	cp = malloc(sizeof(char) * len + 1);
	if (!cp)
		return (NULL);
	while (i < len)
	{
		cp[i] = s[i];
		i++;
	}
	cp[i] = 0;
	return (cp);
}
