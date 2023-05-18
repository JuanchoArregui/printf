/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:02:59 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/18 13:29:42 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	//FORBIDDEN. just for testing purposes
#include <unistd.h> //this is for using write
#include <stdarg.h> //this is for variadic functions
// #include <string.h> //this is for handling strings

typedef struct s_print
{
	int	partial;
	int	total;
}	t_print;
typedef enum boolean
{
	false,
	true
}	t_bool;

void			ft_putchar(char c);
void			ft_putstring(char *s);
void			ft_putnumber(int nb);
int				ft_puthexa(unsigned long int nb, t_bool upper);
int				ft_puthexa_marker(void);
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

int	ft_puthexa(unsigned long int nb, t_bool upper)
{
	char	*hexa;
	int		res[100];
	int		i;
	int		partial;

	if (upper)
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	i = 0;
	while (nb > 16)
	{
		res[i] = hexa[nb % 16];
		nb /= 16;
		i++;
	}
	res[i] = hexa[nb];
	partial = i + 1;
	while (i >= 0)
	{
		ft_putchar(res[i]);
		i--;
	}
	return (partial);
}

int	ft_puthexa_marker(void)
{
	write(1, "0x", 2);
	return (2);
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
	struc->partial = 0;
	if (*text == '%')
	{
		write(1, "%", 1);
		struc->partial = 1;
	}
	else if (*text == 'c')
	{
		char	c;
		
		c = va_arg(arg, int);
		ft_putchar(c);
		struc->partial = 1;
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
	else if (*text == 'p')
	{
		unsigned long int	ptr;

		struc->partial = ft_puthexa_marker();
		ptr = va_arg(arg, unsigned long int);
		struc->partial += ft_puthexa(ptr, false);
	}
	else if (*text == 'x')
	{
		unsigned int x;
		
		x = va_arg(arg, unsigned int);
		struc->partial = ft_puthexa(x, false);
	}
	else if (*text == 'X')
	{
		unsigned int x;
		
		x = va_arg(arg, unsigned int);
		struc->partial = ft_puthexa(x, true);
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

	struc->partial = 0;
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
// %% 	print a percent sign
// %c 	character
// %s 	a string of characters
// %p 	pointer hexadecimal address



// %d 	decimal (integer) number (base 10)
// %i 	integer (base 10)
// %u 	unsigned decimal (integer) number

// %x 	number in hexadecimal (base 16)
// %X 	number in hexadecimal (base 16)




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

	const char *string = "1$..!";
	++string;
	printf("\nTEST 4 - %%, caracter y puntero");
	int res41 =    printf("\nimprimiendo un símbolo de porcentaje \"%%\", un carácter que debe ser un dolar \"%c\" y la dirección del puntero: %p", *string, &string);
	int res42 = ft_printf("\nimprimiendo un símbolo de porcentaje \"%%\", un carácter que debe ser un dolar \"%c\" y la dirección del puntero: %p", *string, &string);
	char *restest4 = res41 == res42 ? "OK" : "FAILLLLL";
	printf("\nres printf: %i\nres ft_printf: %i",res41, res42);
	printf("\nTEST 4 - %s", restest4);


	printf("\n\nTEST 5 - variables HEXA\n");
	int res51 =    printf("\nhexa del numero '34467797' en minúsculas: %x, y en mayúsculas: %X", 34467797, 34467797);
	int res52 = ft_printf("\nhexa del numero '34467797' en minúsculas: %x, y en mayúsculas: %X", 34467797, 34467797);
	char *restest5 = res51 == res52 ? "OK" : "FAILLLLL";
	printf("\nres printf: %i\nres ft_printf: %i",res51, res52);
	printf("\nTEST 5 - %s", restest5);
	return (0);

}
