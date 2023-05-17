/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:02:59 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/17 12:14:16 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	//FORBIDDEN. just for testing purposes
#include <unistd.h> //this is for using write
#include <stdarg.h> //this is for variadic functions
// #include <string.h> //this is for handling strings

typedef struct s_print
{
	int		partial;
	int		total;
}	t_print;
void			ft_putchar(char c);
void			ft_putstring(char *s);
void			ft_putnumber(int nb);
void			ft_puthexa(unsigned int nb);

unsigned long	ft_len_str(const char *s);
int				ft_len_int(int nb, char c);
const char		*ft_txt_find_pcnt(const char *s);
const char		*ft_txt_read_until_pcnt(const char *text, t_print *struc);
const char		*ft_txt_do_pcnt(const char *text, t_print *struc, va_list arg);
int				ft_printf(const char *text, ...);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstring(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnumber(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
			ft_putstring("-2147483648");
		else
		{
			ft_putchar('-');
			ft_putnumber(-nb);
		}
	}
	else if (nb > 10)
	{
		ft_putnumber(nb / 10);
		ft_putnumber(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}

void	ft_puthexa(unsigned int x)
{
	char	*hexa;
	int		res[100];
	int		i;

	hexa = "0123456789abcdef";
	i = 0;
	while (x > 16)
	{
		res[i] = hexa[x % 16];
		x /= 16;
		i++;
	}
	res[i] = hexa[x];
	while (i >= 0)
	{
		ft_putchar(res[i]);
		i--;
	}
}

unsigned long	ft_len_str(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

const char	*ft_txt_find_pcnt(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}

int	ft_len_int(int nb, char c)
{
	int	i;
	int	number;
	int	neg;

	if (!nb)
		return (1);
	else if (nb < 0)
	{
		neg = 1;
		number = -nb;
	}
	else
	{
		neg = 0;
		number = nb;
	}

	i = 0;
	if (c == 'i')
	{
		while (number)
		{
			number /= 10;
			i++;
		}
		return (i + neg);
	}
	else if (c == 'd')
	{
		while (number)
		{
			number /= 10;
			i++;
		}
		return (i + neg);
	}
	else if (c == 'x')
	{
		while (number)
		{
			number /= 16;
			i++;
		}
		return (i);
	}
	return (0);
}

const char	*ft_txt_do_pcnt(const char *text, t_print *struc, va_list arg)
{
	if (*text == '%')
	{
		write(1, "%", 1);
		struc->partial = 1;
	}
	else if (*text == 'i')
	{
		int	nb;
		
		nb = va_arg(arg, int);
		ft_putnumber(nb);
		struc->partial = ft_len_int(nb, *text);
	}
	else if (*text == 'd')
	{
		int d;
		
		d = va_arg(arg, int);
		ft_putnumber(d);
		struc->partial = ft_len_int(d, *text);
	}
	else if (*text == 's')
	{
		char	*s;

		s = va_arg(arg, char *);
		if (!s)
		{
			write(1, "(null)", 6);
			struc->partial = 6;
		}
		else
		{
			ft_putstring(s);
			struc->partial = ft_len_str(s);
		}
	}
	else if (*text == 'x')
	{
		unsigned int x;
		
		x = va_arg(arg, unsigned int);
		ft_puthexa(x);
		struc->partial = ft_len_int((int)x, *text);
	}
	else
	{
		struc->partial = 0;
		return (NULL);
	}
	struc->total += struc->partial;
	return (++text);
}

const char	*ft_txt_read_until_pcnt(const char *text, t_print *struc)
{
	int			text_length;
	const char	*next;
	int			next_length;

	text_length = ft_len_str(text);
	next = ft_txt_find_pcnt(text);
	next_length = ft_len_str(next);
	struc->partial = text_length - next_length;
	write(1, text, struc->partial);
	struc->total += struc->partial;
	return (next);
}

int	ft_printf(const char *text, ...)
{
	va_list	args;
	t_print	struc;

	va_start(args, text);
	struc.partial = 0;
	struc.total = 0;
	while (*text)
	{
		if (*text == '%')
			text = ft_txt_do_pcnt(++text, &struc, args);
		else
			text = ft_txt_read_until_pcnt(text, &struc);
	}
	va_end(args);
	return (struc.total);
}

//
//
//
//TESTING
//
//
// %p 	pointer hexadecimal address

// %d 	decimal (integer) number (base 10)
// %i 	integer (base 10)
// %u 	unsigned decimal (integer) number

// %x 	number in hexadecimal (base 16)
// %X 	number in hexadecimal (base 16)


// %c 	character
// %s 	a string of characters
// %% 	print a percent sign


int	main(void)
{
	printf("\n\nTEST 1 - varios integer");
	int	res11 = printf("\nhola qué tal %i, %i, %i... probando", -111, 222, -333);
	int	res12 = ft_printf("\nhola qué tal %i, %i, %i... probando", -111, 222, -333);
	char *restest1 = res11 == res12 ? "OK" : "FAILLLLL";
	printf("\nres printf: %i\nres ft_printf: %i",res11, res12);
	printf("\nTEST 1 --> %s", restest1);



	printf("\n\nTEST 2 - Variable tipo STRING NULL");
	int res21 = printf("\nvamos con un string nulo --> %s", NULL);
	int res22 = ft_printf("\nvamos con un string nulo --> %s", NULL);
	char *restest2 = res21 == res22 ? "OK" : "FAILLLLL";
	printf("\nres printf: %i\nres ft_printf: %i",res21, res22);
	printf("\nTEST 2 - %s\n", restest2);


	printf("\n\nTEST 3 - variable tipo STRING en el medio\n");
	int res31 = printf("\nvamos con un %s en el medio\n", "\"string\"");
	int res32 = ft_printf("\nvamos con un %s en el medio\n", "\"string\"");
	char *restest3 = res31 == res32 ? "OK" : "FAILLLLL";
	printf("\nres printf: %i\nres ft_printf: %i",res31, res32);
	printf("\nTEST 3 - %s", restest3);


	printf("\nTEST 4 - %% y decimal");
	int res41 = printf("\nimprimiendo un símbolo de porcentaje \"%%\", un carácter \"%c\"y un número dcimal", "$");
	int res42 = ft_printf("\nimprimiendo un símbolo de porcentaje \"%%\", un carácter \"%c\"y un número dcimal", "$");
	char *restest4 = res41 == res42 ? "OK" : "FAILLLLL";
	printf("\nres printf: %i\nres ft_printf: %i",res41, res42);
	printf("\nTEST 4 - %s", restest4);



	return (0);

}
