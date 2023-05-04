/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:02:59 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/05 00:31:57 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	//FORBIDDEN. just for testing purposes
#include <unistd.h> //this is for using write
#include <stdarg.h> //this is for variadic functions
// #include <string.h> //this is for handling strings

typedef struct s_print
{
	int		width;
	int		length;
}	t_print;
void			ft_putchar(char c);
void			ft_putstring(char *s);
void			ft_putnumber(int nb);
void			ft_puthexa(unsigned int nb);

unsigned long	ft_len_str(const char *s);
int				ft_len_int(int nb, char c);
char			*ft_text_find_percent(const char *s);
const char		*ft_text_read(char const *text, t_print *struc);
const char		*ft_text_percent(const char *text, t_print *struc, va_list arg);
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
	char	*hexa = "0123456789abcdef";
	int res[100];
	int i = 0;

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

char	*ft_text_find_percent(const char *s)
{
	while (*s)
	{
		if (*s == '%')
		{
			// printf("\n-----> (char *)s: %s", (char *)s);
			// printf("\n-----> *s: %c\n", *s);
			return ((char *)s);
		}
		s++;
	}
	if (!s)
		return ((char *)s);
	return (NULL);
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
		number = -nb;
	}
	if (c == 'd')
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

const char		*ft_text_percent(const char *text, t_print *struc, va_list arg)
{
	if (*text == 'd')
	{
		int d = va_arg(arg, int);
		ft_putnumber(d);
		struc->length = ft_len_int(d, *text);
	}
	else if (*text == 's')
	{
		char *s = va_arg(arg, char *);
		if (!s)
		{
			write(1, "(null)", 6);
			struc->length += 6;
		}
		else
		{
			ft_putstring(s);
			struc->length = ft_len_str(s);
		}
	}
	else if (*text == 'x')
	{
		unsigned int x = va_arg(arg, unsigned int);
		ft_puthexa(x);
		struc->length = ft_len_int((int)x, *text);
	}
	else
		return (NULL);
	text++;
	return (text);
	
}

const char	*ft_text_read(char const *text, t_print *struc)
{
	char	*next;

	next = ft_text_find_percent(text);
	if (next)
		struc->width = next - text;
	else
		struc->width = ft_len_str(text);
	write(1, text, struc->width);
	struc->length += struc->width;
	while (*text && *text != '%')
		++text;
	return (text);
}

int	ft_printf(const char *text, ...)
{
	va_list	args;
	t_print	struc;
	int		i;

	i = 0;
	va_start(args, text);
	struc.width = 0;
	struc.length = 0;
	while (*text)
	{
		printf("\n-ITERACION: %i", i);
		printf("\n-char entrada: %c", *text);
		printf("\n-string pendiente entrada: %s", (char *)text);
		if (*text == '%')
		{
			// printf("||1st char antes de ft_text_percent '%c'||", *text);
			text = ft_text_percent(text, &struc, args);
		}
		else
		{
			// printf("||1st char antes de ft_text_read '%c'||", *text);
			text = ft_text_read(text, &struc);
		}
		printf("\n-char salida: %c", *text);
		printf("\n-string pendiente salida: %s", (char *)text);

		// if (!text)
		// {
		// 	write(1, "(null)", 6);
		// 	va_end(args);
		// 	return (struc.length);
		// }
		++i;
		++text;
	}
	va_end(args);
	return (struc.length);
}

//
//
//
//TESTING
//
//
//
// %c 	character
// %d 	decimal (integer) number (base 10)
// %e 	exponential floating-point number
// %f 	floating-point number
// %i 	integer (base 10)
// %o 	octal number (base 8)
// %s 	a string of characters
// %u 	unsigned decimal (integer) number
// %x 	number in hexadecimal (base 16)
// %% 	print a percent sign
// \% 	print a percent sign

int	main(void)
{
	printf("\nTEST 1");
	
	int	res11 = printf("\nhola qué tal %i, %i, %i... probando\n", 1, 2, 3);
	int	res12 = ft_printf("\nhola qué tal %i, %i, %i... probando\n", 1, 2, 3);
	char *restest1;
	if (res11 == res12)
		restest1 = "OK";
	else
		restest1 = "FAILLLLL";
	printf("\nres printf: %i\nres ft_printf: %i",res11, res12);
	printf("\nTEST 1 --> %s", restest1);

	// //TEST 2 - 1 variable tipo STRING NULL
	// printf("\nTEST 2\n");
	// printf("Variable tipo STRING NULL\n");
	// int res21 = printf("vamos con un %s\n", NULL);
	// int res22 = ft_printf("vamos con un %s\n", NULL);
	// char *restest2 = res21 == res22 ? "OK" : "FAILLLLL";
	// printf("res printf: %i\nres ft_printf: %i\n",res21, res22);
	// printf("TEST 2 - %s\n", restest2);

	// //TEST 3 - 1 variable tipo STRING en el medio
	// printf("\nTEST 3\n");
	// printf("1 variable tipo STRING en el medio\n");
	// int res31 = printf("vamos con un %s en el medio\n", "string");
	// int res32 = ft_printf("vamos con un %s en el medio\n", "string");
	// char *restest3 = res31 == res32 ? "OK" : "FAILLLLL";
	// printf("res printf: %i\nres ft_printf: %i\n",res31, res32);
	// printf("TEST 3 - %s\n", restest3);


	// //TEST 4 - 1 variable tipo INTEGER
	// printf("\nTEST 4\n");
	// printf("1 variable tipo INTEGER\n");
	// int res41 = printf("integer: %i\n", 2456345);
	// int res42 = ft_printf("integer: %i\n", 2456345);
	// char *restest4 = res41 == res42 ? "OK" : "FAILLLLL";
	// printf("res printf: %i\nres ft_printf: %i\n",res41, res42);
	// printf("TEST 4 - %s\n", restest4);

	// printf("Solo TEXTO, sin variables\n");

	return (0);

}
