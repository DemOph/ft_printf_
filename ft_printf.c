/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 11:25:41 by chael-ha          #+#    #+#             */
/*   Updated: 2020/07/15 17:34:23 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
    int i;

    if (!(p = (z_format_placeholder *) malloc (sizeof(z_format_placeholder))))
    return 0;
    i = 0;
    count = 0;
    va_start(ap, fmt);
    while (fmt[i])
    {
        if (fmt[i] != '%')
        {
            ft_putchar_fd(fmt[i], 1);
            count++;
        }
        else
            i = get_infos((char *)fmt, i + 1, ap, p);
        i++;
    }
    va_end(ap);
    free(p);
    return(count);
}