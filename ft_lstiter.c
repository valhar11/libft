/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:40:21 by vlibert           #+#    #+#             */
/*   Updated: 2023/06/01 15:09:35 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*actual;
	t_list	*following;

	if (!lst)
		return ;
	actual = lst;
	if (f)
	{
		while (actual != 0)
		{
			following = actual->next;
			f(actual->content);
			actual = following;
		}
	}
}
