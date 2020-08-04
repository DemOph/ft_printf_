/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:07:09 by chael-ha          #+#    #+#             */
/*   Updated: 2019/11/20 15:57:30 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (ft_memcmp(dst, src, len) == 0)
		return (dst);
	if (dst > src)
	{
		while (len--)
		{
			*(unsigned char*)(dst + len) = *(unsigned char*)(src + len);
		}
		return (dst);
	}
	while (i < len)
	{
		*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
		i++;
	}
	return (dst);
}
