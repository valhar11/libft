/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:06:38 by vlibert           #+#    #+#             */
/*   Updated: 2023/05/04 17:17:27 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int x)
{
	if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0'
			&& x <= '9'))
	{
		return (1);
	}
	return (0);
}
