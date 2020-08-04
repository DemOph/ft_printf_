/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:42:50 by chael-ha          #+#    #+#             */
/*   Updated: 2019/11/20 17:10:36 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!*needle)
		return ((char*)haystack);
	if (!haystack && len == 0)
		return (NULL);
	str = (char*)haystack;
	while (str[i] != '\0')
	{
		j = 0;
		while (j + i < (int)len && needle[j] && str[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}
