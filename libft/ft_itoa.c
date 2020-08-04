/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:56:35 by chael-ha          #+#    #+#             */
/*   Updated: 2019/11/07 18:11:14 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_of_n(int n)
{
	int		res;

	res = 0;
	if (n < 0)
		res++;
	if (n == 0)
		return (1);
	while (n)
	{
		res++;
		n /= 10;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		l;
	int		j;

	l = ft_len_of_n(n);
	if (!(res = (char*)malloc((l + 1) * sizeof(char))))
		return (NULL);
	res[l] = '\0';
	if (l == 1)
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		j = 1;
	}
	else
		j = 0;
	while (l-- > j)
	{
		res[l] = '0' + (n % 10) * (n < 0 ? -1 : 1);
		n /= 10;
	}
	return (res);
}
