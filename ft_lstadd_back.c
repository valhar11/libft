/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:59:46 by vlibert           #+#    #+#             */
/*   Updated: 2023/05/22 17:51:54 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*to_add;

	if (new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			to_add = ft_lstlast(*lst);
			to_add->next = new;
		}
	}
	return ;
}
