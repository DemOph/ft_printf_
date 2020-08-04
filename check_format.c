/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 09:33:51 by chael-ha          #+#    #+#             */
/*   Updated: 2020/08/02 18:41:45 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    check_format(char c, va_list ap, z_format_placeholder *p)
{
	if (c == 'c')
        ft_print_char(ap, p);
	else if (c == 's')
		ft_print_str(ap, p);
	if (c == 'p' || c == 'x' || c == 'X')
		ft_print_p(ap,p,c);
	if (c == 'd' || c == 'i')
		ft_print_d(ap,p);
	if (c == 'u')
		ft_print_u(ap,p);
	if (c == '%')
		ft_print_pourcent();
}