/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prec_minus_s.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:37:46 by chael-ha          #+#    #+#             */
/*   Updated: 2020/07/19 11:25:41 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_print_prec_minus_s(char *s, char *s1, z_format_placeholder *p, int l_str, int w_p)
{
    if (((p->precision == 1 && 
        *s == *s1) || (p->precision == 0 && l_str == 0))
        && p->width >= 1)
        while (p->width -- > 0)
        {
            ft_putchar_fd(' ', 1);
            count++;
        }
    else
    {
        while (s[j] && l_str-- && p->precision--)
        {
           ft_putchar_fd(s[j++],1);
           count++;
        }
        while (w_p-- > 0 && p->width != 0)
        {
            ft_putchar_fd(' ', 1);
            count++;
        }
    }
    return(s && s1 && l_str && w_p);
}