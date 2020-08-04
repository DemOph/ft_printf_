/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 18:57:50 by chael-ha          #+#    #+#             */
/*   Updated: 2020/08/02 18:21:40 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void   ft_print_u_basic(unsigned int nb)
{
    ft_putnbr_u(nb,1);
    count += cout_digit(nb);
}
void    ft_print_u_width_minus(unsigned int nb)
{
    int esp;
    count += cout_digit(nb);
    ft_putnbr_u(nb,1);
    esp = p->width - cout_digit(nb);
    while (esp-- > 0)
    {
        ft_putchar_fd(' ',1);
        count++;
    }
}
void    ft_print_u_width(unsigned int nb)
{
    int esp;
    esp = p->width - cout_digit(nb);
    if (p->flag == '-' || p->width < 0)
    {
        if (p->width < 0)
            p->width = -1*p->width;
        ft_print_u_width_minus(nb);
    }
    else
    {
        while (esp-- > 0)
        {
            ft_putchar_fd(' ',1);
            count++;
        }
        count += cout_digit(nb);
        ft_putnbr_u(nb,1);
    }
}
void    ft_print_u_prec(unsigned int nb)
{
    int zero;
    zero = p->precision - cout_digit(nb);
    while (zero -- > 0)
    {
        ft_putchar_fd('0',1);
        count++;
    }
    count += cout_digit(nb);
    ft_putnbr_u(nb,1);
}
void    ft_print_zero_flag_u(unsigned int nb)
{
    int zero_flag;
    zero_flag = p->width - cout_digit(nb);
    while (zero_flag -- > 0)
    {
        ft_putchar_fd('0',1);
        count++;
    }
    count += cout_digit(nb);
    ft_putnbr_u(nb,1);
}
void    ft_print_u_width_prec_minus(unsigned int nb, int esp, int zero)
{
    while (zero -- > 0)
    {
        ft_putchar_fd('0',1);
        count++;
    }
    count += cout_digit(nb);
    ft_putnbr_u(nb,1);
    while(esp-- > 0)
    {
        ft_putchar_fd(' ',1);
        count++;
    }
}
void    ft_print_u_width_prec_non_minus(unsigned int nb, int esp, int zero)
{
    while(esp-- > 0)
    {
        ft_putchar_fd(' ',1);
        count++;
    }
    while (zero -- > 0)
    {
        ft_putchar_fd('0',1);
        count++;
    }
    count += cout_digit(nb);
    ft_putnbr_u(nb,1);
}
void    ft_print_u_width_prec(unsigned int nb)
{
    int esp;
    int zero;
    esp = p->width - cout_digit(nb);
    zero = p->precision - cout_digit(nb);
    if (p->precision < p->width && cout_digit(nb) < p->precision)
        esp = p->width - p->precision;
    if (p->flag == '-')
        ft_print_u_width_prec_minus(nb,esp,zero);
    else
        ft_print_u_width_prec_non_minus(nb,esp,zero);
}
void    ft_print_u_val0()
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
void    ft_print_u(va_list ap, z_format_placeholder *p)
{
    int nb;
    nb = va_arg(ap,unsigned int);
    if (nb == 0 && p->precision == 0)
        ft_print_u_val0();
    else if ((p->width == p->precision)
            ||(p->width == 0 && p->precision == -1)
            || (p->width < cout_digit(nb) && p->width > 0
                && p->precision < cout_digit(nb))
            ||(p->width == 0 && p->precision < -1))
        ft_print_u_basic(nb);
    else if (p->flag == '0' && p->precision == -1)
        ft_print_zero_flag_u(nb);
    else if (p->width != 0 && (p->precision == -1 || p->precision == 0))
        ft_print_u_width(nb);
    else if ((p->width == 0 && p->precision > cout_digit(nb)) 
            || (p->width < p->precision))
        ft_print_u_prec(nb);
    else if (p->width > 0 && p->precision > -1)
        ft_print_u_width_prec(nb);
}