/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Dec_to_Hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 08:11:11 by chael-ha          #+#    #+#             */
/*   Updated: 2020/08/04 21:12:55 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_Dec_to_Hex(unsigned long nb, char c)
{
    char *h;
    h = (char *)malloc(count_hex(nb)+1);
    int rest;
    j = 0;
    if (nb == 0)
        h[j++] = '0';
    while (nb > 0)
    {
        rest = nb % 16;
        nb /= 16;
        if (rest >= 0 && rest <= 9)
            h[j] = rest + '0' ;
        else if (rest >= 10 && rest <= 15)
        {
            if (c == 'x' || c == 'p')
                h[j] = rest + 'W';
            if (c == 'X')
                h[j] = rest + '7';
        }
        j++;
    }
    h[j] = '\0';
    while(h[--j] && j != -1)
    {
        ft_putchar_fd(h[j],1);
        count++;
    }
    if (c == 'p')
        count += 2;
    free(h);
}