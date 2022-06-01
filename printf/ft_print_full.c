/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:35:59 by jibang            #+#    #+#             */
/*   Updated: 2022/05/14 17:13:28 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
// #include "./libft/libft.h" //not working


void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putstr(char *s, int *len)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		*len += 1;
		i++;
	}
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}



//------putnbr_fd---------
static void putnbr(int n, int *len)
{
    char    nb;

    if (n >= 10)
        putnbr(n / 10, len);
    nb = '0' + n % 10;
    write(1, &nb, 1);
	*len += 1;
}

void    ft_putnbr(int n, int *len)
{
    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
		*len += 11;
        return ;
    }
    if (n < 0)
    {
        n *= -1;
        write(1, "-", 1);
		*len += 1;
    }
    putnbr(n, len);
}

//------putnbr_unsign---------

static void putnbr_u(unsigned int n, int *len)
{
    char    nb;

    if (n >= 10)
        putnbr_u(n / 10, len);
    nb = '0' + n % 10;
    write(1, &nb, 1);
	*len += 1;
}

void    ft_putnbr_unsign(unsigned int n, int *len)
{ 
    putnbr_u(n, len);
}



//----------ft_putnbr_base-----------------

static unsigned int	base_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_putnbr_base(unsigned int nbr, char *base, int *len)
{
	
		if (nbr >= base_len(base))
		{
			ft_putnbr_base((nbr / base_len(base)), base, len);
			ft_putnbr_base((nbr % base_len(base)), base, len);
		}
		else
		{
			write(1, &base[nbr], 1);
			len += 1;
		}
}

//-------ft_print_mem_address------------

/*
static 	base_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
*/

void	ft_print_memory(unsigned long long nbr, char *base, int *len)
{
		if (nbr >= (unsigned long long)base_len(base))
		{
			ft_print_memory((nbr / base_len(base)), base, len);
			ft_print_memory((nbr % base_len(base)), base, len);
		}
		else
		{
			write(1, &base[nbr], 1);
			len += 1;
		}
}

void	ft_print_mem_address(unsigned long long nbr, int *len)
{
	ft_putstr("0x", len);
	ft_print_memory(nbr, "0123456789abcdef", len);
}

//--------ft_parse-----------
int	ft_parse(va_list ap, char *str, int *len)
{
	size_t	i;
	char	*s;
	char	c;
	int		d;
	unsigned int	u;
	unsigned int		x;
	unsigned int		X;
	void	*p;

	i = 0;
	while (str[i])
	{
		if  (str[i] != '%')
			ft_putchar(str[i], len);
		else if (str[i] == '%' && str[i + 1] != '\0')
		{
			if (str[i + 1] == 's')
			{
				s = va_arg(ap, char *);
				ft_putstr(s, len);
			}
			else if (str[i + 1] == 'c')
			{
				c = va_arg(ap, int);
				ft_putchar(c, len);
			}
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
			{
				d = va_arg(ap, int);
				ft_putnbr(d, len);
			}
			else if (str[i + 1] == 'u')
			{
				u = va_arg(ap, unsigned int);
				ft_putnbr_unsign(u, len);
			}
			else if(str[i + 1] == 'x')
			{
				x = va_arg(ap, unsigned int);
				ft_putnbr_base(x, "0123456789abcdef", len);
			}
			else if(str[i + 1] == 'X')
			{
				X = va_arg(ap, unsigned int);
				ft_putnbr_base(X, "0123456789ABCDEF", len);
			}
			else if (str[i + 1] == 'p')
			{
				p = va_arg(ap, void *);
				ft_print_mem_address((unsigned long long)p, len); //to print adress, make it unsigned long long 
			}
			else if (str[i + 1] == '%')
				ft_putchar('%', len);
			else
				ft_putstr("[format error]\n", len);
			i++;

		}
		else
			ft_putstr("[format error]]\n", len);
		i++;
	}
	return (*len);
}

//--------ft_printf---------------
int	ft_printf(const char *str, ...)	
{
	va_list	ap;
	//using static var, we can count the len of the whole string.
	int len;

	len = 0;
	va_start(ap, str);
	len = ft_parse(ap, (char *)str, &len);
	va_end(ap);
	return (len);
}


//--------------main------------------
int	main()
{
	char s1[] = "hello";
	char s2[] = "world";
	void *p = s1;
	int num = -2147483648;
	int	num2 = (int)-15;
	int	num3 = -2147483647;
	int	n = 0;
	int n1 = 0;

	printf("printf %%p: %p\n", p);
	printf("printf %%u: %u\n",0xa);
	printf("printf %%x: %x\n", 15);
	printf("printf %%i: %i\n", -0xa);
	printf("printf %%x: %x\n", -1);
	printf("printf %%x: %x\n", -15);
	printf("printf %%x: %x\n", -25);
	printf("printf %%x: %x\n", 15);
	printf("printf %%u: %u, %u , %u\n", num, num2, num3);
	printf("test:: %d %w\n", 1, 12);
	ft_printf("--------------------------------\n");
	ft_printf("ft_printf %%X: %X\n", num2);
	ft_printf("ft_printf %%x: %x\n", -1);
	ft_printf("ft_printf %%x: %x\n", -15);
	ft_printf("ft_printf %%x: %x\n", -25);
	ft_printf("ft_printf %%X: %X\n", 15);
	ft_printf("ft_printf %%u: %u, %u , %u\n", num, num2, num3);
	ft_printf("wow chin gu deul! %%  bbak bbak e ah jo ssi ya!\n");
	ft_printf("ft_printf %%d %d\n", 0xf);
	ft_printf("what you input: %c  %s  %s  %c %p\n ", 'b', s1, s2, 'z', p); 
	ft_printf("test:: %d %w\n", 1, 12);
	n = ft_printf("again you input: %c yey! %s yay %s lololo %c\n", 'b', "'hello'", "'world'", 'z'); 
	n1 = ft_printf("djaskl%cdjasd%s\n", 'K', "hello");

	printf("%d\n", n);
	printf("%d\n", n1);
	return (0);
}
