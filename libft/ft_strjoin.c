/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:57:40 by chael-ha          #+#    #+#             */
/*   Updated: 2019/11/10 15:45:15 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;
	size_t		len_s1;
	size_t		len_s2;
	char		*ptr;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(ptr = (char *)malloc(len_s1 + len_s2 + 1)))
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
