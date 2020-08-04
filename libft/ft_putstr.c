#include "libft.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putstr(char  *s)
{
	unsigned int i;

	i = -1;
	while (++i < ft_strlen(s))
		ft_putchar(s[i]);
}