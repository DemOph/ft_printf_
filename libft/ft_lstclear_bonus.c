/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:45:38 by chael-ha          #+#    #+#             */
/*   Updated: 2019/11/08 21:45:41 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *lst;
	while (tmp)
	{
		(*del)(tmp->content);
		prev = tmp;
		(tmp) = (tmp)->next;
		free(prev);
	}
	free(tmp);
	*lst = NULL;
}
