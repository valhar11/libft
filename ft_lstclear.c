/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:06:19 by vlibert           #+#    #+#             */
/*   Updated: 2023/06/01 15:04:39 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*following;
	t_list	*actual;

	if (!lst | !del)
		return ;
	actual = *lst;
	if (actual)
	{
		while (actual)
		{
			following = actual->next;
			ft_lstdelone(actual, del);
			actual = following;
		}
		*lst = 0;
	}
}
