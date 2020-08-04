/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:10:17 by chael-ha          #+#    #+#             */
/*   Updated: 2019/11/10 15:31:29 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*tab;

	i = 0;
	if (!s)
		return (NULL);
	tab = ft_strdup(s);
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		tab[i] = f(i, tab[i]);
		i++;
	}
	return (tab);
}
