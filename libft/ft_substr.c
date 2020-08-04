/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:38:33 by chael-ha          #+#    #+#             */
/*   Updated: 2019/11/10 15:39:22 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	l;
	char	*ptr;

	j = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(&s[start]);
	if (start > ((unsigned int)ft_strlen(s)))
		return (ft_strdup(""));
	if (l >= len)
		l = len;
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (len + 1))))
		return (NULL);
	while (j < l && s[start])
	{
		ptr[j] = s[start];
		start++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
