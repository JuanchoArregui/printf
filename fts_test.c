/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:38:45 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/22 13:47:44 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// -
// -
// -
// -
// -
// -
// NOTA, COSAS A CONTINUAR:
// - REvisar función	ft_len_int(int nb, char c) que ahora no usamos, aunque habría que mirar el tema de los negativos 
// y probablemente borrarlo o ver código tb con ft_len_str
// - Continuar revisando la función fT_test para que imprima bien los test.
// --
// -
// -
// -
// --
// -
// -






#include "ft_printf.h"
#include <stdio.h>

typedef struct s_test
{
	int	counter;
	int	title;
	int	ft_printf;
	int	printf;
}	t_test;

void	ft_test(const char *text, ...)
{
	int		res;
	int		res_ft;
	char	*result;
	va_list	args;

	va_start(args, text);
	res = printf(text, args);
	res_ft = ft_printf(text, args);
	if (res == res_ft)
		result = "OK";
	else
		result = "FAILLLLL";
	printf("\nres printf: %i\nres ft_printf: %i", res, res_ft);
	printf("\nTEST 1 --> %s", result);
	va_end(args);
}

void	ft_test_print_title(t_test *struc)
{
	printf("\n\nTEST %i", struc->counter);
	struc->counter += 1;
}


int	main(void)
{
	t_test	struc;

	struc.counter = 0;
	ft_test_print_title(&struc);
	ft_test("\n%i, %i, %i... probando", 1, 1, 3);

	ft_test_print_title(&struc);
	ft_test("\nnum negativo: %i", -111);


	// printf("\n\nTEST 1 - varios integer");
	// int	res11 = printf("\nhola qué tal %i, %i, %i... probando", -111, 222, -333);
	// int	res12 = ft_printf("\nhola qué tal %i, %i, %i... probando", -111, 222, -333);
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
	return (0);

}
