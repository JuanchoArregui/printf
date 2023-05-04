/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:02:59 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/04 13:42:11 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	//FORBIDDEN. just for testing purposes
#include <unistd.h> //this is for using write
#include <stdarg.h> //this is for variadic functions
// #include <string.h> //this is for handling strings

void			ft_putchar(char c);
void			ft_putstring(char *s);
void			ft_putnumber(int nb);
unsigned long	ft_strlen(const char *s);
char			*ft_strpercent(const char *s);
int				ft_printf(char const *placeholders, ...);

typedef struct s_print
{
	int		width;
	int		length;
}	t_print;

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
	else {
		ft_putchar(nb + 48);
	}
}

unsigned long	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strpercent(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			return ((char *)s);
		s++;
	}
	if (!s)
		return ((char *)s);
	return (NULL);
}



const char	*ft_read_text(t_print *my_struct, char const *placeholders)
{
	char*next;

	return(placeholders);
}

int	ft_printf(char const *placeholders, ...)
{
	va_list	args;
	t_print	my_struc;

	my_struc.width = 0;
	my_struc.length = 0;
	// int		i;
	// int		x;
	// double	dbl;
	// int		num_args;

	va_start(args, placeholders);
	while (*placeholders)
	{
		if (*placeholders == '%')
			printf("\nHemos encontrado un%%!!!!\n");
		else
		{
			ft_read_text(&my_struc, placeholders);
			printf("%c", *placeholders);
		}
		placeholders++;
	}
	printf("\n");
	va_end(args);
	
	return (0);
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
	ft_printf("hola este es mi printf, aquí va un número:%c y aquí un string:%s\n");

	ft_putstring("hola este es mi printf, aquí va un número:%c y aquí un string:%s\n");

	ft_putnumber(1234);
	ft_printf("\n");
	ft_putnumber(-2147483648);
	ft_printf("\n");
	ft_putnumber(-2147483647);
	ft_printf("\n");

	

	return (0);
}
