/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 19:12:55 by chael-ha          #+#    #+#             */
/*   Updated: 2020/07/25 10:09:09 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n, int fd)
{
	if (n == 4294967295)
	{
		ft_putchar_fd('4',1);
		ft_putnbr_u(294967295, fd);
		return ;
	}
	if (n > 9)
		ft_putnbr_u(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
