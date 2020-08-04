/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:44:22 by chael-ha          #+#    #+#             */
/*   Updated: 2019/11/08 21:44:25 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	temp = (*alst);
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
