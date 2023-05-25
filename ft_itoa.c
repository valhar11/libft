/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:29:38 by vlibert           #+#    #+#             */
/*   Updated: 2023/05/11 15:40:03 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getalen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	ft_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		i;
	int		sign;

	i = ft_getalen(n);
	sign = ft_sign(n);
	array = malloc(sizeof(char) * i + 1);
	if (!array)
		return (NULL);
	array[i--] = 0;
	if (n < 0)
		array[0] = 45;
	if (n == 0)
		array[0] = '0';
	while (n)
	{
		array[i] = sign * (n % 10) + '0';
		i--;
		n = n / 10;
	}
	return (array);
}

/*
int main()
{
	int nb = -1234;
	char *array = ft_itoa(nb);
	int i = 0;
	while(array[i])
		printf("%c", array[i++]);
}
*/