/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 07:32:13 by chael-ha          #+#    #+#             */
/*   Updated: 2020/07/15 18:11:23 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void    ft_print_width_s(char *s, z_format_placeholder *p, int l_str)
{
    int nb_esp;
    int prec;
    
    j = 0;
    l_str1 = l_str;
    nb_esp = p->width - l_str;
    prec = p->precision;
    if (p->flag == '-')
        ft_print_width_minus_s(s, nb_esp);
    while ((nb_esp-- > 0 && s[j] != '\0') 
        || (l_str == 0 && (p->width - prec) == 0 && p->precision-- > 0)
        || (l_str == 0 && (p->width - prec) < 0 && p->width-- > 0))
        {
            ft_putchar_fd(' ', 1);
            count++;
        }
    while(s[j] && l_str--)
        {
            ft_putchar_fd(s[j++],1);
            count++;
        }
}

void    ft_print_prec_s(char *s, z_format_placeholder *p, int l_str)
{
    int w_p;
    int prec;
    char *s1;

    j = 0;
    prec = p->precision;
    w_p = p->width - prec;
    s1 = "(null)";
    if (p->flag == '-')
        ft_print_prec_minus_s(s,s1,p,l_str,w_p);
    else
        ft_print_prec_non_minus_s(s,s1,p,l_str,w_p);
}

void    ft_print_str(va_list ap, z_format_placeholder *p)
{
    int  l_str;
    char    *s;
    s = va_arg(ap, char*);
    if (s)
        l_str = (int)ft_strlen(s);
    else
    {
        s = "(null)";
        l_str = (int)ft_strlen(s);
    }
    if (p->width == 0 && p->precision == -1)
        ft_print_s_basic(s,l_str);
    if (p->precision == -1 && p->width >= 1)
        ft_print_width_s(s,p,l_str);
    else if (p->precision != -1 && p->width == 0)
        ft_print_prec_s(s,p,l_str);
    else if (p->precision != -1 && p->width > 0)
    {
        if (l_str < p->width && l_str < p->precision)
            ft_print_width_s(s,p,l_str);
        else
            ft_print_prec_s(s,p,l_str);
    }
}