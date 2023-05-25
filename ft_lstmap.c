/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:53:51 by vlibert           #+#    #+#             */
/*   Updated: 2023/05/22 17:44:11 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*following;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	lst = lst->next;
	following = new_lst;
	while (lst)
	{
		following->next = ft_lstnew(f(lst->content));
		if (!following->next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		following = following->next;
		lst = lst->next;
	}
	following->next = 0;
	return (new_lst);
}
