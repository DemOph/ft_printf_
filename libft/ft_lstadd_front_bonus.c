/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:44:07 by chael-ha          #+#    #+#             */
/*   Updated: 2019/11/08 21:44:10 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_empty(t_list *liste)
{
	if (liste == NULL)
		return (0);
	return (1);
}

void		ft_lstadd_front(t_list **alst, t_list *new)
{
	if (is_empty(*alst) == 1 && new)
		new->next = *alst;
	*alst = new;
}
