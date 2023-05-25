/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:06:19 by vlibert           #+#    #+#             */
/*   Updated: 2023/05/22 17:51:19 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*following;

	if (*lst)
	{
		while (*lst)
		{
			following = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = following;
		}
		*lst = 0;
	}
}
