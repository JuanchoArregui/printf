/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:38:45 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/03 17:27:39 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




// - Continuar revisando la función fT_test para que imprima bien los test. de momento ya parece que me guarda OK la salida de printf
// --
// -
// -
// -
// --
// -
// -

#include "ft_printf.h"
#include <stdio.h>//esto es para poder usar el printf real
#include <limits.h>//esto es para saber los limites de int en nuestro sistema

// CONTINUAR AQUIIII
// vsprintf paraece que guarda ok el sring en el buffer. Ver si lo dejamos así o si usamos un malloc o una estructura.
// Terminar de verificar el vsprintf y comenzar a hacer los test por aquí.

// Nota: ver tb que pasa con los números negativos que parece que me da segmentation fault

// Y ver enunciado los tipos que nos piden



void	ft_test(const char *text, ...)
{
	va_list	args;
	int	length;
	t_print	struc;
	// char	*ret_pf;
	// char	*ret_ft_pf;

	struc.print = (char *)malloc(MAX_LENGTH * sizeof(char));
	struc.print[0] = '\0';
	va_start(args, text);

	char buffer[MAX_LENGTH];  // Buffer para almacenar el string formateado
	vsprintf(buffer, text, args);
	length = ft_len_str(buffer);
	printf("\nBuffer: %s", buffer);
	printf("\nBuffer length: %i", length);



	va_end(args);
	free(struc.print);

}


void	test_00(void)
{
 	char character = 'k';
    char string[] = "Esto es un string";

	printf("\n\nTEST 00 - impreme un CARACTER y un STRING");
	ft_printf("\nEl carácter es: \"%c\" y el string es: \"%s\"", character, string);
	ft_test("\nEl carácter es: \"%c\" y el string es: \"%s\"", character, string);
}

void	test_01(void)
{
 	int min = -2147483648;
 	int max = 2147483647;
	int length;

	printf("\n\nTEST 01 - variables tipo INT min y max");
	ft_test("\nEl entéro mínimo es: \"%i\" y el máximo es: \"%i\"", min, max);
	length = printf("\nEl entéro mínimo es: \"%u\" y el máximo es: \"%u\"", min, max);
	printf("\nprintf length: %i", length);

}

// typedef struct s_test_general
// {
// 	int	counter;
// 	int	title;
// }	t_test_general;

// typedef struct s_test
// {
// 	char	out_pf[4096];
// 	char	out_ft_pf[4096];
// 	int		ret_pf;
// 	int		ret_ft_pf;
// 	char	*result;
// }	t_test;

// void	ft_test(const char *text, ...)
// {
// 	va_list	args;
// 	t_test	test;

// 	va_start(args, text);
// 	test.ret_pf = vsnprintf(test.out_pf, sizeof(test.out_pf), text, args);
// 	test.ret_ft_pf = ft_len_str(test.out_ft_pf);

	

// 	//Revisar esta parte y ver si asi tiene sentido
// 	//si hay que modificar la función s_ft_printf
// 	//Y si sería mejor hacerlo con un puntero, y reservarle memoria con malloc
// 	ft_strlcpy(test.out_ft_pf, s_ft_printf(text, args), size_t size);

	
// 	va_end(args);
// 	if (ft_strcmp(test.out_pf, test.out_ft_pf) == 1)
// 		test.result = "KO";
// 	if (test.ret_ft_pf != test.ret_pf)
// 		test.result = "KO";
// 	if (test.result == "KO")
// 		test.result = "\033[1;31m [ FAILLLLL ] \033[1;0m";
// 	else
// 		test.result = "\033[1;32m [ OK ] \033[1;0m";
// 	printf("\n%s", test.out_pf);
// 	printf("\n%s", test.out_ft_pf);
// 	printf("\n%i", test.ret_pf);
// 	printf("\n%i", test.ret_ft_pf);
// 	printf("\nTEST result --> %s", test.result);
// 	va_end(args);
// }




// void	ft_test_print_title(t_test_general *struc)
// {
// 	printf("\n\n\033[1;36mTEST %i\033[1;0m", struc->counter);
// 	struc->counter += 1;
// }


int	main(void)
{
	printf("El valor máximo de int es: %d\n", INT_MAX);
    printf("El valor mínimo de int es: %d\n", INT_MIN);
	test_00();
	test_01();


	

    

	// printf("\n\nTEST 0");
	// printf("\n");
	// int res01 = printf("\n123456789öu'o'eè``_%% %%");
	// printf("\n");
	// int res02 = ft_printf("\n123456789öu'o'eè``_%% %%");
	// char *restest2 = res01 == res02 ? "OK" : "FAILLLLL";
	// printf("\nres printf: %i\nres ft_printf: %i",res01, res02);
	// printf("\nTEST 2 - %s\n", restest2);




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
	return (0);

}

