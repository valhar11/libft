/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:46:19 by vlibert           #+#    #+#             */
/*   Updated: 2023/06/01 14:41:57 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(char a)
{
	if (a == 45)
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	r;
	int		sign;
	long	temp;

	r = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == 45 || str[i] == 43)
		sign = ft_sign(str[i++]);
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = r;
		r = r * 10 + (str[i] - '0');
		i++;
		if (r < temp && sign == 1)
			return (-1);
		else if (r < temp && sign == -1)
			return (0);
	}
	return (r * sign);
}
