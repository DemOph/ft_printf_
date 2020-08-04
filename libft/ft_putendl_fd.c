/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:28:10 by chael-ha          #+#    #+#             */
/*   Updated: 2019/11/10 15:50:44 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	size_t	len_s;

	if (!s)
		return ;
	i = 0;
	len_s = ft_strlen(s);
	while (i < len_s)
		ft_putchar_fd(s[i++], fd);
	ft_putchar_fd('\n', fd);
}
