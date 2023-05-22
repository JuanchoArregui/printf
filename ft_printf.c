/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:02:59 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/22 10:21:21 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	main(void)
{
	printf("Hola Mundo");
}


// int	main(void)
// {
// 	printf("\n\nTEST 1 - varios integer");
// 	int	res11 = printf("\nhola qué tal %i, %i, %i... probando", -111, 222, -333);
// 	int	res12 = ft_printf("\nhola qué tal %i, %i, %i... probando", -111, 222, -333);
// 	char *restest1 = res11 == res12 ? "OK" : "FAILLLLL";
// 	printf("\nres printf: %i\nres ft_printf: %i",res11, res12);
// 	printf("\nTEST 1 --> %s", restest1);

// 	printf("\n\nTEST 2 - Variable tipo STRING NULL");
// 	int res21 = printf("\nvamos con un string nulo --> %s", NULL);
// 	int res22 = ft_printf("\nvamos con un string nulo --> %s", NULL);
// 	char *restest2 = res21 == res22 ? "OK" : "FAILLLLL";
// 	printf("\nres printf: %i\nres ft_printf: %i",res21, res22);
// 	printf("\nTEST 2 - %s\n", restest2);

// 	printf("\n\nTEST 3 - variable tipo STRING en el medio\n");
// 	int res31 = printf("\nvamos con un %s en el medio\n", "\"string\"");
// 	int res32 = ft_printf("\nvamos con un %s en el medio\n", "\"string\"");
// 	char *restest3 = res31 == res32 ? "OK" : "FAILLLLL";
// 	printf("\nres printf: %i\nres ft_printf: %i",res31, res32);
// 	printf("\nTEST 3 - %s", restest3);

// 	const char *string = "1$..!";
// 	++string;
// 	printf("\nTEST 4 - %%, caracter y puntero");
// 	int res41 =    printf("\nimprimiendo un símbolo de porcentaje \"%%\", un carácter que debe ser un dolar \"%c\" y la dirección del puntero: %p", *string, &string);
// 	int res42 = ft_printf("\nimprimiendo un símbolo de porcentaje \"%%\", un carácter que debe ser un dolar \"%c\" y la dirección del puntero: %p", *string, &string);
// 	char *restest4 = res41 == res42 ? "OK" : "FAILLLLL";
// 	printf("\nres printf: %i\nres ft_printf: %i",res41, res42);
// 	printf("\nTEST 4 - %s", restest4);

// 	printf("\n\nTEST 5 - variables HEXA\n");
// 	int res51 =    printf("\nhexa del numero '34467797' en minúsculas: %x, y en mayúsculas: %X", 34467797, 34467797);
// 	int res52 = ft_printf("\nhexa del numero '34467797' en minúsculas: %x, y en mayúsculas: %X", 34467797, 34467797);
// 	char *restest5 = res51 == res52 ? "OK" : "FAILLLLL";
// 	printf("\nres printf: %i\nres ft_printf: %i",res51, res52);
// 	printf("\nTEST 5 - %s", restest5);
// 	return (0);

// }
