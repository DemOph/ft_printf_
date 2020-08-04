/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:46:11 by chael-ha          #+#    #+#             */
/*   Updated: 2019/11/08 21:46:15 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new_list;
	t_list		*head;

	if (lst == NULL || f == NULL || !del)
		return (NULL);
	if (!(head = ft_lstnew((*f)(lst->content))))
	{
		ft_lstclear(&head, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		if (!(new_list = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_list);
		lst = lst->next;
	}
	return (head);
}
