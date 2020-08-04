#include <stdio.h>
#include "ft_printf.h"
#include <ctype.h>

int main()
{
    //ft_Dec_to_Hex(1234);
    //int a = ft_printf("%-2.3s\n", "s");
    //int a = 10;
    //int *ptr = &a;
    //int a = ft_printf("%*d\n",-5,2);
    //printf("%d\n", a);
    int b = ft_printf("%x\n", 4294967296);
    printf("%d\n", b);
    int c = printf("%x\n", 4294967296);
    printf("%d\n", c);
    //ft_putnbr_u(-4,1);
    //printf("\n");
    //printf("%d\n", e);
    //int c = printf("%u\n","hi");
    //printf("%d\n", c);
    //printf(" main count %d\n", count);
    //char *s;
    //s = ft_Dec_to_Hex(15);
    //ft_printf("%-030c",'b');
    //int w = ft_printf("%11c",'m');
    //printf("%d\n", w);
    //printf("%d",atoi("11c"));
    //write(1, "vibe check", 11);
    //return 0;
}