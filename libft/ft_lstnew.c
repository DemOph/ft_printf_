/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:54:34 by chael-ha          #+#    #+#             */
/*   Updated: 2019/10/28 18:12:47 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *tab;
	if (!(tab = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tab->content = content;
	tab->next = NULL;
	return(tab);
}
int main()
{
	int i;
	t_list *lst;
	t_list *new;

	i = 1;
	new = ft_lstnew("world");
	lst = ft_lstnew("hello");
	lst->next = new;
	//ft_lstadd_back(&lst, new);
	while (lst)
	{
		printf("ele list %d = %s\n", i, lst->content);
		lst = lst->next;
		i++;
	}
}
