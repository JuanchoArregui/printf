/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_test_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:38:45 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/05 03:33:46 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>//esto es para poder usar el printf real

void	test_00(void)
{
	// printf("\n\nTESTS GROUP 0 - CHARACTERS\n");

	// ft_printf_test("%c", 'a');
	// ft_printf_test("%c%c%c*", '\0', '1', 1);
	// ft_printf_test("%c small string", 'a');
	// ft_printf_test("%c small string", '\0');
	// ft_printf_test("the char is: %c", 'a');
	// ft_printf_test("the char is: %c", '\0');
	// ft_printf_test("n%cs", 'a');
	// ft_printf_test("%c%c%c%c%c", 'a', 'i', 'u', 'e', 'o');
	// ft_printf_test("l%cl%cl%cl%cl%c", 'a', 'i', 'u', 'e', 'o');
	// ft_printf_test("l%cl%cl%cl%cl%c", '\0', '\0', '\0', 'e', '\0');
}

void	test_01(void)
{
	// printf("\n\nTESTS GROUP 1 - STRINGS\n");
	
	// char *null_str = NULL;
	// ft_printf_test("%s", "");
	// ft_printf_test("this is a %s", "test");
	// ft_printf_test("this is 1 %s with %s %s", "test", "multiple", "strings");
	// ft_printf_test("%s%s%s%s", "This ", "is", " an ugly ", "test");
	// ft_printf_test("%s", "This is a rather simple test.");
	// ft_printf_test("%s", "-2");
	// ft_printf_test("%s", "-24");
	// ft_printf_test("%s", "-stop");
	// ft_printf_test("%s", "\n\n\"@#~½¬{[]ññöóC€€ßßßßssSSº1ª}");
	// ft_printf_test("%s", "-0003");
	// ft_printf_test("%s", "000-0003");
	// ft_printf_test("%s", "0x42");
	// ft_printf_test("%s", "0x0000042");
	// ft_printf_test("some naugty tests: %s", "0000%");
	// ft_printf_test("some naugty tests: %s", "    %");
	// ft_printf_test("some naugty tests: %s", "%000");
	// ft_printf_test("%s", "bea thought but bea forgot the loop that the chars cause she was floaty during the amsterdam siren call. she got me by surprise you probably read my mind that look in your eyes and judging by your own cries you probably read my mind this is a really long string and if you see this you must look at your return values!kthxbai this must have more than 127 chars by now isnt it ok 4242 4 life 1337 code everyday to the moon!");
	// ft_printf_test("%s", null_str);
	// ft_printf_test("%s everywhere", null_str);
	// ft_printf_test("everywhere %s", null_str);
	// ft_printf_test("%s", "h");
	// ft_printf_test("t%st%s", "a", "u");
	// ft_printf_test("%s%s%s%s%s%s", "a", "i", "u", "e", "o", "l");
}

void	test_02(void)
{
	printf("\n\nTESTS GROUP 2 - POINTERS\n");

	int test = 42;
	ft_printf_test("%p", &test);
	ft_printf_test("%p is a virtual memory address", &test);
	ft_printf_test("The address of the answer is %p", &test);
	ft_printf_test("The address is %p, so what?", &test);
	int *ptr = &test;
	ft_printf_test("A pointer at %p points to %p", &test, &ptr);
	ft_printf_test("This %p is a very strange address", (void *)(long int)test);

	char *mallocked = malloc(2);
	ft_printf_test("This %p is an address from the heap", mallocked);
	free(mallocked);
	
	ft_printf_test("%p", NULL);
	ft_printf_test("The NULL macro represents the %p address", NULL);
	ft_printf_test("This %p is even stranger", (void *)-1);
}

void	test_03(void)
{
	ft_printf("\n\nTEST 01 - caracteres raros y con SIMBOLO PORCENTAJE");
	ft_printf_test("\nªº!@~#=?¿\n12345\n6789\"\'''öu'o'eèü¢``_%% %%");


	ft_printf("\n\nTEST 02 - string con INT intercalados");
	ft_printf_test("\nhola qué tal %i, %i, %i... probando", 1, 2, 3);


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