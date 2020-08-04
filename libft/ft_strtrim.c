/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:24:59 by chael-ha          #+#    #+#             */
/*   Updated: 2019/11/10 15:46:34 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	return_index_start(char const *s1, char const *set)
{
	int			i;
	int			j;
	int			start;
	int			len_set;

	i = 0;
	j = 0;
	start = 0;
	len_set = ft_strlen(set);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i] != set[j] && j < len_set)
			j++;
		start = i;
		if (!set[j])
			break ;
		i++;
	}
	return (start);
}

static size_t	return_index_stop(char const *s1, char const *set)
{
	int			j;
	int			stop;
	int			len_s1;
	int			len_set;

	j = 0;
	stop = 0;
	len_s1 = ft_strlen(s1);
	len_set = ft_strlen(set);
	while (len_s1--)
	{
		j = 0;
		while (s1[len_s1] != set[j] && j < len_set)
			j++;
		stop = len_s1;
		if (!set[j])
			break ;
	}
	return (stop);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*ptr;
	size_t		i;
	size_t		a;
	size_t		b;

	i = 0;
	if (!s1)
		return (NULL);
	a = return_index_stop(s1, set);
	b = return_index_start(s1, set);
	if (b == (ft_strlen(s1) - 1) || a == 0)
		return (ft_strdup(""));
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (a - b + 2))))
		return (NULL);
	while (b <= a)
		ptr[i++] = s1[b++];
	ptr[i] = '\0';
	return (ptr);
}
