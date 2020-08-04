/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_basic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 08:41:17 by chael-ha          #+#    #+#             */
/*   Updated: 2020/07/19 08:41:42 by chael-ha         ###   ########.fr       */
/*                                                                       */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_print_p_basic(unsigned long nb, char c)
{
    int nb_zero;
    nb_zero = p->precision - count_hex(nb);
    if (nb == 0 && p->precision == 0)
        return;
    else if (c == 'p')
        ft_putstr("0x");
    if (p->flag == '0' && p->precision >count_hex(nb))
        while (nb_zero-- > 0)
        {
            ft_putchar_fd('0',1);
            count++;
        }
    ft_Dec_to_Hex(nb,c);
}