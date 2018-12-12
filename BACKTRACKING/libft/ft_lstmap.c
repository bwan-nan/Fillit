/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:37:29 by cnotin            #+#    #+#             */
/*   Updated: 2018/11/20 11:47:20 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*n_lst;
	t_list	*begin_lst;

	if (lst)
	{
		if (!(n_lst = f(ft_lstnew(lst->content, lst->content_size))))
			return (NULL);
		begin_lst = n_lst;
		if (lst->next)
		{
			lst = lst->next;
			while (lst)
			{
				n_lst->next = f(ft_lstnew(lst->content, lst->content_size));
				n_lst = n_lst->next;
				lst = lst->next;
			}
		}
		return (begin_lst);
	}
	return (NULL);
}
