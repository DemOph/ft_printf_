/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:14:10 by chael-ha          #+#    #+#             */
/*   Updated: 2020/07/14 19:44:03 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void    init_format_placeholder (z_format_placeholder *p)
{
    p->flag = 'q'; //- 0 . *
    p->width = 0;
    p->precision = -1;
    p->type = 'z';
}

int get_infos(char *fmt, int i, va_list ap, z_format_placeholder *p)
{
    init_format_placeholder (p);
    while (fmt[i] == '-' || fmt[i] == '0')
    {
        if (p->flag == 'q' && fmt[i] == '0')
            p->flag = '0';
        if (fmt[i] == '-')
            p->flag = '-';
        i++;
    }
    if (ft_isdigit(fmt[i]))
    {
        p->width = ft_atoi(&fmt[i]);
        i += cout_digit(p->width);
    }
    if (fmt[i] == '*')
    {
        p->width = va_arg(ap, int);
        i++;
    }
    if (fmt[i] == '.')
    {
        i++;
        p->precision = 0;
        if (fmt[i] == '*')
        {
            p->precision = va_arg(ap, int);
            i++;
        }
        while (ft_isdigit(fmt[i]))
        {
            p->precision = ft_atoi(&fmt[i]);
            i += cout_digit(p->precision);
            //i++;
        }
        if (fmt[i] == '*')
        {
            p->precision = va_arg(ap, int);
            i++;
        }
    }
    if (ft_isalpha(fmt[i]) || fmt[i] == '%')
        {
            p->type = fmt[i];
            check_format(fmt[i], ap, p);
        }
    return (i);
}