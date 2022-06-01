#include <stdio.h>
#include "ft_printf.h"

//--------------main------------------
int main()
{
    char s1[] = "hello";
    char s2[] = "world";
    void *p = s1;
    int num = -2147483648;
    int num2 = (int)-15;
    int num3 = -2147483647;
    int n = 0;
    int n1 = 0;

    printf("printf %%p: %p\n", p);
/*	printf(" %p ", -1);
    printf(" %p ", 1);
    printf(" %p ", 15);
    printf(" %p ", 16);
    printf(" %p ", 17);
//    printf(" %p %p ", LONG_MIN, LONG_MAX));
//    printf(" %p %p ", INT_MIN, INT_MAX));
//    printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
     printf(" %p %p ", 0, 0);
	 */
    printf("printf %%u: %u\n",0xa);
    printf("printf %%x: %x\n", 15);
    printf("printf %%i: %i\n", -0xa);
    printf("printf %%x: %x\n", -1);
    printf("printf %%x: %x\n", -15);
    printf("printf %%x: %x\n", -25);
    printf("printf %%x: %x\n", 15);
    printf("printf %%u: %u, %u , %u\n", num, num2, num3);
    printf("printf:  NULL %s NULL ", NULL);
	printf("\n");
	printf("%s", NULL);
	printf("\n");
   	ft_printf("--------------------------------\n");
    ft_printf("ft_printf %%p: %p\n", p);
    ft_printf("ft_printf %%X: %X\n", num2);
    ft_printf("ft_printf %%x: %x\n", -1);
    ft_printf("ft_printf %%x: %x\n", -15);
    ft_printf("ft_printf %%x: %x\n", -25);
    ft_printf("ft_printf %%X: %X\n", 15);
    ft_printf("ft_printf %%u: %u, %u , %u\n", num, num2, num3);
    ft_printf("wow chin gu deul! %%  bbak bbak e ah jo ssi ya!\n");
    ft_printf("ft_printf %%d %d\n", 0xf);
    ft_printf("what you input: %c  %s  %s  %c %p\n", 'b', s1, s2, 'z', p);
    ft_printf("ft_printf : NULL %s NULL ", NULL);
	ft_printf("\n");
	ft_printf("%s", NULL);
	ft_printf("\n");
    n = ft_printf("again you input: %c yey! %s yay %s lololo %c\n", 'b', "'hello'", "'world'", 'z');
    n1 = ft_printf("djaskl%cdjasd%s\n", 'K', "hello");

    printf("%d\n", n);
    printf("%d\n", n1);
    return (0);
}
