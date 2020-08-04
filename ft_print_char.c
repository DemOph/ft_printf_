/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 09:28:46 by chael-ha          #+#    #+#             */
/*   Updated: 2020/07/13 21:37:44 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_char(va_list ap, z_format_placeholder *p)
{
    int j;
    
    j = p->width;
    if ((p->flag) == '-')
    {
        ft_putchar_fd(va_arg(ap, int), 1);
        while(p->width-- > 1)
           ft_putchar_fd(' ', 1);
    }
    else if (p->flag == 'q')
    {
        while(p->width-- > 1)
            ft_putchar_fd(' ', 1);
        ft_putchar_fd(va_arg(ap, int), 1);
    }
    count += j;
}