/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:46:19 by vlibert           #+#    #+#             */
/*   Updated: 2023/05/25 15:48:49 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sign(char a)
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
		r = r * 10 + (str[i] - '0');
		i++;
		if ((r < 0 && sign == 1))
			return (0);
		else if (r < 0 && sign == -1)
			return (-1);
	}
	return (r * sign);
}
