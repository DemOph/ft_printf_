/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 11:19:15 by chael-ha          #+#    #+#             */
/*   Updated: 2020/08/02 18:44:57 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct a_format_placeholder
{
    char    flag; //- 0 . *
    int     width;
    int     precision;
    char    type;
} z_format_placeholder;

int count;
int j;
int l_str1;
int prec;
z_format_placeholder *p;
va_list ap;

int     ft_printf(const char *, ...);
int     get_infos(char *fmt, int i, va_list ap, z_format_placeholder *p);
void    check_format(char c, va_list ap, z_format_placeholder *p);
int     cout_digit(long i);
void    ft_print_char(va_list ap, z_format_placeholder *p);
void    ft_print_str(va_list ap, z_format_placeholder *p);
void    ft_print_s_basic(char *s, int l_str);
int     ft_print_width_minus_s(char *s, int nb_esp);
int     ft_print_prec_minus_s(char *s, char *s1, z_format_placeholder *p, int l_str, int w_p);
int     ft_print_prec_non_minus_s(char *s, char *s1, z_format_placeholder *p,int l_str, int w_p);
void    ft_print_p(va_list ap, z_format_placeholder *p, char c);
void    ft_Dec_to_Hex(unsigned long nb, char c);
int     count_hex(unsigned long nb);
void    ft_print_p_basic(unsigned long nb, char c);
void    ft_print_p_zero(z_format_placeholder *p, unsigned long nb, char c);
void    ft_print_pourcent();
void    ft_print_d(va_list ap, z_format_placeholder *p);
void    ft_print_u(va_list ap, z_format_placeholder *p);
void    ft_putnbr_u(unsigned int n, int fd);
 
#endif