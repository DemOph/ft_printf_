/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:17:55 by chael-ha          #+#    #+#             */
/*   Updated: 2019/11/20 16:01:23 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l_dest;
	size_t	l_src;
	size_t	l;

	i = 0;
	l_src = ft_strlen(src);
	if (!dst && size == 0)
		return (l_src);
	l_dest = ft_strlen(dst);
	l = l_dest;
	if (size <= l_dest)
		return (l_src + size);
	else
	{
		while (src[i] && l_dest < size - 1)
			dst[l_dest++] = src[i++];
		dst[l_dest] = '\0';
		return (l + l_src);
	}
}
