/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 10:25:20 by chael-ha          #+#    #+#             */
/*   Updated: 2020/08/04 10:38:10 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_print_p_zero(z_format_placeholder *p, unsigned long nb, char c)
{
    int nb_zero;
    nb_zero = p->precision - count_hex(nb);
    if (c == 'p')
        ft_putstr("0x");
    while (nb_zero -- > 0)
        {
            ft_putchar_fd('0',1);
            count++;
        }
    ft_Dec_to_Hex(nb,c);
    
}