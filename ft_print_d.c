/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 08:24:31 by chael-ha          #+#    #+#             */
/*   Updated: 2020/08/04 20:16:40 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void   ft_print_d_basic(int nb)
{
    ft_putnbr_fd(nb,1);
    if (nb < 0)
        count++;
    count += cout_digit(nb);
}

void    ft_print_d_width_minus(int nb)
{
    int esp;
    count += cout_digit(nb);
    ft_putnbr_fd(nb,1);
    esp = p->width - cout_digit(nb);
    if (nb < 0)
        esp--;
    while (esp-- > 0)
    {
        ft_putchar_fd(' ',1);
        count++;
    }
}

void    ft_print_d_width(int nb)
{
    int esp;
    esp = p->width - cout_digit(nb);
    if (nb < 0)
    {
        count++;
        esp--;
    }
    if (p->flag == '-' || p->width < 0)
    {
        if (p->width < 0)
            p->width = -1*p->width;
        ft_print_d_width_minus(nb);
    }
    else
    {
        while (esp-- > 0)
        {
            ft_putchar_fd(' ',1);
            count++;
        }
        count += cout_digit(nb);
        ft_putnbr_fd(nb,1);
    }
}

void    ft_print_d_prec(int nb)
{
    int zero;
    zero = p->precision - cout_digit(nb);
    if (nb < 0)
    {
        count++;
        ft_putchar_fd('-',1);
    }
    while (zero -- > 0)
    {
        ft_putchar_fd('0',1);
        count++;
    }
    count += cout_digit(nb);
    if (nb < 0)
        ft_putnbr_fd(-nb,1);
    else
        ft_putnbr_fd(nb,1);
}

void    ft_print_zero_flag(int nb)
{
    int zero_flag;
    zero_flag = p->width - cout_digit(nb);
    if (nb < 0)
    {
        count++;
        ft_putchar_fd('-',1);
        zero_flag--;
    }
    while (zero_flag -- > 0)
    {
        ft_putchar_fd('0',1);
        count++;
    }
    count += cout_digit(nb);
    if (nb < 0)
        ft_putnbr_fd(-nb,1);
    else
        ft_putnbr_fd(nb,1);
}

void    ft_print_d_width_prec_minus(int nb, int esp, int zero)
{
    if (nb < 0)
    {
        ft_putchar_fd('-',1);
        count++;
        nb = -nb;
    }
    while (zero -- > 0)
    {
        ft_putchar_fd('0',1);
        count++;
    }
    count += cout_digit(nb);
    ft_putnbr_fd(nb,1);
    while(esp-- > 0)
    {
        ft_putchar_fd(' ',1);
        count++;
    }
}
void    ft_print_d_width_prec_non_minus(int nb, int esp, int zero)
{
    while(esp-- > 0)
    {
        ft_putchar_fd(' ',1);
        count++;
    }
    if (nb < 0)
    {
        ft_putchar_fd('-',1);
        count++;
        nb = -nb;
    }
    while (zero -- > 0)
    {
        ft_putchar_fd('0',1);
        count++;
    }
    count += cout_digit(nb);
    ft_putnbr_fd(nb,1);   
}
void    ft_print_width_prec(int nb)
{
    int esp;
    int zero;
    esp = p->width - cout_digit(nb);
    zero = p->precision - cout_digit(nb);
    if (p->precision < p->width && cout_digit(nb) < p->precision)
        esp = p->width - p->precision;
    if (nb < 0)
        esp--;
    if (p->flag == '-')
        ft_print_d_width_prec_minus(nb,esp,zero);
    else
        ft_print_d_width_prec_non_minus(nb,esp,zero);
}
void    ft_print_d_val0()
{
    if (p->width == 0)
        return;
    if (p->width > 0)
        while(p->width -- > 0)
        {
            ft_putchar_fd(' ',1);
            count++;
        }
}

void    ft_print_d(va_list ap, z_format_placeholder *p)
{
    int nb;
    nb = va_arg(ap,int);
    if (nb == 0 && p->precision == 0)
        ft_print_d_val0();
    else if ((p->width == p->precision)
            ||(p->width == 0 && p->precision == -1)
            || (p->width < cout_digit(nb) && p->width > 0
                && p->precision < cout_digit(nb))
            ||(p->width == 0 && p->precision < -1))
        ft_print_d_basic(nb);
    else if (p->flag == '0' && p->precision == -1)
        ft_print_zero_flag(nb);
    else if (p->width != 0 && (p->precision == -1 || p->precision == 0))
        ft_print_d_width(nb);
    else if ((p->width == 0 && p->precision > cout_digit(nb)) 
            || (p->width < p->precision))
        ft_print_d_prec(nb);
    else if (p->width > 0 && p->precision > -1)
        ft_print_width_prec(nb);
}