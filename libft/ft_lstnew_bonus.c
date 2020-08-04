/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:43:48 by chael-ha          #+#    #+#             */
/*   Updated: 2019/11/08 21:43:51 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list *tab;

	if (!(tab = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tab->content = content;
	tab->next = NULL;
	return (tab);
}
