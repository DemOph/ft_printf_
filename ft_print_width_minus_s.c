/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width_minus_s.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:47:22 by chael-ha          #+#    #+#             */
/*   Updated: 2020/07/15 17:24:36 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_print_width_minus_s(char *s, int nb_esp)
{   
    while(s[j] && l_str1--)
    {
        ft_putchar_fd(s[j++],1);
        count++;  
    }
    while (nb_esp-- > 0)
    {
        ft_putchar_fd(' ', 1); 
        count++;
    }
    return(l_str1 && nb_esp);
}
              