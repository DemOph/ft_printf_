/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:39:34 by chael-ha          #+#    #+#             */
/*   Updated: 2020/08/04 10:37:56 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_print_p_null()
{
    int nb_esp;
    nb_esp = p->width - 5;
    if (p->flag == '-')
    {
        ft_putstr_fd("(nil)",1);
        count+=5;
        while (nb_esp-->0)
        {
            ft_putchar_fd(' ',1);
            count++;
        }
    }
    else
    {
        while (nb_esp-->0 && p->width > 5)
        {
            ft_putchar_fd(' ',1);
            count++;
        }
        ft_putstr_fd("(nil)",1);
        count+=5;
    }
}

void    ft_print_p_width(unsigned long nb, int nb_esp, char c)
{
    if (nb == 0 && p->precision != -1)
        nb_esp++;
    if (p->flag == '0' && (p->precision > count_hex(nb) || p->precision == -1))
        while (nb_esp-- > 0)
        {
            ft_putchar_fd('0',1);
            count++;
        }
    else
        while (nb_esp-- > 0)
        {
            ft_putchar_fd(' ',1);
            count++;
        }
    if (c == 'p')
        ft_putstr("0x");
    if (nb != 0 || (nb == 0 && p->precision == -1))
        ft_Dec_to_Hex(nb,c);
}

void    ft_print_p_width_minus(unsigned long nb, int nb_esp, char c)
{
    if (nb == 0 && p->precision == 0)
        nb_esp++;
    if (c == 'p')
        ft_putstr("0x");
    if (nb != 0 || (nb == 0 && p->precision != 0))
        ft_Dec_to_Hex(nb,c);   
    while (nb_esp-- > 0)
    {
        ft_putchar_fd(' ',1);
        count++;
    }
}

void    ft_print_w_p_zero_minus(unsigned long nb, char c, z_format_placeholder *p)
{
    int nb_esp;
    int nb_zero;
    nb_esp = p->width - p->precision;
    if (c == 'p')
        nb_esp -= 2;
    nb_zero = p->precision - count_hex(nb);
    if (c == 'p')
        ft_putstr("0x");
    while (nb_zero-- > 0)
    {
        ft_putchar_fd('0',1);
        count++;
    }
    ft_Dec_to_Hex(nb,c);
    while (nb_esp-- > 0)
    {
        ft_putchar_fd(' ',1);
        count++;
    }
}
void    ft_print_w_p_zero(unsigned long nb,char c, z_format_placeholder *p)
{
    int nb_esp;
    int nb_zero;
    if (p->flag == '-')
        ft_print_w_p_zero_minus(nb,c,p);
    else
    {
        nb_esp = p->width - p->precision;
        if (c == 'p')
            nb_esp -= 2;
        nb_zero = p->precision - count_hex(nb);
        while (nb_esp-- > 0)
        {
            ft_putchar_fd(' ',1);
            count++;
        }
        if (c == 'p')
            ft_putstr("0x");
        while (nb_zero-- > 0)
        {
            ft_putchar_fd('0',1);
            count++;
        }
        ft_Dec_to_Hex(nb,c);
    }
}
void    ft_print_p(va_list ap, z_format_placeholder *p,char c)
{
    unsigned long nb;
    int nb_esp;
    nb = va_arg(ap, unsigned long);
    if (!nb && c == 'p')
        ft_print_p_null();
    else if ((p->width == 0 &&
            (p->precision == -1 || p->precision <= count_hex(nb)))
            || (p->precision == p->width))
        ft_print_p_basic(nb,c);
    else if ((p->width > p->precision && count_hex(nb) > p->precision)
            || (p->width != 0 && p->precision == -1))
    {
        if (c == 'p')
            nb_esp = p->width - count_hex(nb) - 2;
        else
            nb_esp = p->width - count_hex(nb);
        if (p->flag == '-')
            ft_print_p_width_minus(nb,nb_esp,c);
        else
            ft_print_p_width(nb,nb_esp,c);
    }
    else if (p->precision > count_hex(nb))
        ft_print_w_p_zero(nb,c,p);
    else if (p->width == 0 && p->precision > count_hex(nb))
        ft_print_p_zero(p,nb,c);
}