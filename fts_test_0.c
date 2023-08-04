/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_test_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:38:45 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/04 02:28:47 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>//esto es para poder usar el printf real

void	test_00(void)
{
 	char character = 'k';
    char string[] = "Esto es un string";

	ft_printf("\n\nTEST 00 - impreme un CARACTER y un STRING");
	ft_printf_test("\nEl carácter es: \"%c\" y el string es: \"%s\"", character, string);
}

void	test_01(void)
{
	ft_printf("\n\nTEST 01 - caracteres raros y con SIMBOLO PORCENTAJE");
	ft_printf_test("\nªº!@~#=?¿\n12345\n6789\"\'''öu'o'eèü¢``_%% %%");
}

void	test_02(void)
{
	ft_printf("\n\nTEST 02 - string con INT intercalados");
	ft_printf_test("\nhola qué tal %i, %i, %i... probando", 1, 2, 3);
}

void	test_03(void)
{
 	int min = -2147483648;
 	int max = 2147483647;

	ft_printf("\n\nTEST 01 - variables tipo INT min y max");
	ft_printf_test("\nEl entéro mínimo es: \"%i\" y el máximo es: \"%i\"", min, max);
}




	// printf("\n\nTEST 1 - varios integer");
	// printf("\nprintf:");
	// int	res11 = printf("\nhola qué tal %i, %i, %i... probando", -111, 222, -333);
	// printf("\ft_printf:");
	// ft_printf("\nhola qué tal %i, %i, %i... probando", -111, 222, -333);
	// char *restest1 = res11 == res12 ? "OK" : "FAILLLLL";
	// printf("\nres printf: %i\nres ft_printf: %i",res11, res12);
	// printf("\nTEST 1 --> %s", restest1);









	// printf("\n\nTEST 2 - Variable tipo STRING NULL");
	// int res21 = printf("\nvamos con un string nulo --> %s", NULL);
	// int res22 = ft_printf("\nvamos con un string nulo --> %s", NULL);
	// char *restest2 = res21 == res22 ? "OK" : "FAILLLLL";
	// printf("\nres printf: %i\nres ft_printf: %i",res21, res22);
	// printf("\nTEST 2 - %s\n", restest2);

	// printf("\n\nTEST 3 - variable tipo STRING en el medio\n");
	// int res31 = printf("\nvamos con un %s en el medio\n", "\"string\"");
	// int res32 = ft_printf("\nvamos con un %s en el medio\n", "\"string\"");
	// char *restest3 = res31 == res32 ? "OK" : "FAILLLLL";
	// printf("\nres printf: %i\nres ft_printf: %i",res31, res32);
	// printf("\nTEST 3 - %s", restest3);

	// const char *string = "1$..!";
	// ++string;
	// printf("\n\nTEST 4 - %%, caracter y puntero");
	// int res41 =    printf("\nimprimiendo un símbolo de porcentaje \"%%\", un carácter que debe ser un dolar \"%c\" y la dirección del puntero: %p", *string, &string);
	// int res42 = ft_printf("\nimprimiendo un símbolo de porcentaje \"%%\", un carácter que debe ser un dolar \"%c\" y la dirección del puntero: %p", *string, &string);
	// char *restest4 = res41 == res42 ? "OK" : "FAILLLLL";
	// printf("\nres printf: %i\nres ft_printf: %i",res41, res42);
	// printf("\nTEST 4 - %s", restest4);

	// printf("\n\nTEST 5 - variables HEXA\n");
	// int res51 =    printf("\nhexa del numero '34467797' en minúsculas: %x, y en mayúsculas: %X", 34467797, 34467797);
	// int res52 = ft_printf("\nhexa del numero '34467797' en minúsculas: %x, y en mayúsculas: %X", 34467797, 34467797);
	// char *restest5 = res51 == res52 ? "OK" : "FAILLLLL";
	// printf("\nres printf: %i\nres ft_printf: %i",res51, res52);
	// printf("\nTEST 5 - %s", restest5);