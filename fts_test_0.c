/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_test_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:38:45 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/07 00:44:33 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>//esto es para poder usar el printf real

void	test_00(void)
{
	printf("\n\nTESTS GROUP 0 - CHARACTERS\n");

	ft_printf_test("%c", 'a');
	ft_printf_test("%c%c%c*", '\0', '1', 1);
	ft_printf_test("%c small string", 'a');
	ft_printf_test("%c small string", '\0');
	ft_printf_test("the char is: %c", 'a');
	ft_printf_test("the char is: %c", '\0');
	ft_printf_test("n%cs", 'a');
	ft_printf_test("%c%c%c%c%c", 'a', 'i', 'u', 'e', 'o');
	ft_printf_test("l%cl%cl%cl%cl%c", 'a', 'i', 'u', 'e', 'o');
	ft_printf_test("l%cl%cl%cl%cl%c", '\0', '\0', '\0', 'e', '\0');
}

void	test_01(void)
{
	printf("\n\nTESTS GROUP 1 - STRINGS\n");
	
	char *null_str = NULL;
	ft_printf_test("%s", "");
	ft_printf_test("this is a %s", "test");
	ft_printf_test("this is 1 %s with %s %s", "test", "multiple", "strings");
	ft_printf_test("%s%s%s%s", "This ", "is", " an ugly ", "test");
	ft_printf_test("%s", "This is a rather simple test.");
	ft_printf_test("%s", "-2");
	ft_printf_test("%s", "-24");
	ft_printf_test("%s", "-stop");
	ft_printf_test("%s", "\n\n\"@#~½¬{[]ññöóC€€ßßßßssSSº1ª}");
	ft_printf_test("%s", "-0003");
	ft_printf_test("%s", "000-0003");
	ft_printf_test("%s", "0x42");
	ft_printf_test("%s", "0x0000042");
	ft_printf_test("some naugty tests: %s", "0000%");
	ft_printf_test("some naugty tests: %s", "    %");
	ft_printf_test("some naugty tests: %s", "%000");
	ft_printf_test("%s", "bea thought but bea forgot the loop that the chars cause she was floaty during the amsterdam siren call. she got me by surprise you probably read my mind that look in your eyes and judging by your own cries you probably read my mind this is a really long string and if you see this you must look at your return values!kthxbai this must have more than 127 chars by now isnt it ok 4242 4 life 1337 code everyday to the moon!");
	ft_printf_test("%s", null_str);
	ft_printf_test("%s everywhere", null_str);
	ft_printf_test("everywhere %s", null_str);
	ft_printf_test("%s", "h");
	ft_printf_test("t%st%s", "a", "u");
	ft_printf_test("%s%s%s%s%s%s", "a", "i", "u", "e", "o", "l");
	ft_printf_test("\nvamos con un string nulo --> %s", NULL);
	ft_printf_test("\nvamos con un %s en el medio\n", "\"string\"");


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
	ft_printf_test("The (NIL)) represents position 0 of memory which is a non valid address %p ", NULL);
	ft_printf_test("This %p is even stranger", (void *)-1);
	ft_printf_test("This %p is even stranger", (void *)-2);
	ft_printf_test("This %p is even stranger", (void *)-16);
	ft_printf_test("This %p is even stranger", (void *)-17);
}

void	test_03(void)
{
	printf("\n\nTESTS GROUP 3 - DECIMAL\n");

	int min = -2147483648;
 	int max = 2147483647;
	ft_printf_test("%d", 0);
	ft_printf_test("%d", 10);
	ft_printf_test("%d, %d", 10, 20);
	ft_printf_test("%d%d%d%d", 10, 20, 30, 5);
	ft_printf_test("42 - 84 is %d", -42);
	ft_printf_test("%d C is the lowest temperature in the universe", -273);
	ft_printf_test("\nhola qué tal %d, %d, %d... probando", 1, 2, 3);
	ft_printf_test("\nEl entéro mínimo es: \"%d\" y el máximo es: \"%d\"", min, max);
}

void	test_04(void)
{
	printf("\n\nTESTS GROUP 4 - INT\n");

	ft_printf_test("%i", 0);
	ft_printf_test("%i", 10);
	ft_printf_test("%i, %i", 10, 23);
	ft_printf_test("%i%i%i%i%i%i%i", 10, 23, -2, 37, 200, -9999, 977779);
	ft_printf_test("%i %i", 2147483647, (int)-2147483648);
	ft_printf_test("%iq%i", 21447, -21648);
}

void	test_05(void)
{
	printf("\n\nTESTS GROUP 5 - UNSIGNED\n");
	
	ft_printf_test("%u", 42);
	ft_printf_test("%u", 0);
	ft_printf_test("%u", 2147483647);
	ft_printf_test("%u", (unsigned int)2147483648);
	ft_printf_test("%u", (unsigned int)3147983649);
	ft_printf_test("%u", (unsigned int)4294967295);
	ft_printf_test("%u to the power of %u is %u", 2, 32, (unsigned int)4294967295);
	ft_printf_test("%u%u%u%u", (unsigned int)429896724, 0, 32, (unsigned int)4294967295);
}

void	test_06(void)
{
	printf("\n\nTESTS GROUP 6 - HEXADECIMAL x\n");

	ft_printf_test("%x", 0);
	ft_printf_test("%x", 1);
	ft_printf_test("%x", 10);
	ft_printf_test("%x", 16);
	ft_printf_test("%x", 160);
	ft_printf_test("%x", 255);
	ft_printf_test("%x", 256);
	ft_printf_test("%x", 3735929054u);
	ft_printf_test("the password is %x", 3735929054u);
	ft_printf_test("%x is the definitive answer", 66u);
	ft_printf_test("this is the real number: %x", -1u);
}

void	test_07(void)
{
	printf("\n\nTESTS GROUP 7 - HEXADECIMAL X\n");

	ft_printf_test("%X", 0);
	ft_printf_test("%X", 1);
	ft_printf_test("%X", 10);
	ft_printf_test("%X", 16);
	ft_printf_test("%X", 160);
	ft_printf_test("%X", 255);
	ft_printf_test("%X", 256);
	ft_printf_test("%X", (unsigned int)3735929054);
	ft_printf_test("the password is %X", (unsigned int)3735929054);
	ft_printf_test("%X is the definitive answer", (unsigned int)66);
	ft_printf_test("this is the real number: %X", (unsigned int)-1);
}

void	test_08(void)
{
	printf("\n\nTESTS GROUP 8 - PERCENTAGE\n");

	ft_printf_test("%%");
	ft_printf_test("100%%");
	ft_printf_test("%%p is how you print a pointer in printf");
	ft_printf_test("the '%%%%' is used to print a %% in printf");
	ft_printf_test("%%%%%%%%%%%%%%%%");
	ft_printf_test("%%c%%s%%p%%d%%i%%u%%x%%X%%");
	ft_printf_test("\nªº!@~#=?¿\n12345\n6789\"\'''öu'o'eèü¢``_%% %%");
}

void	test_09(void)
{
	printf("\n\nTESTS GROUP 9 - MIX\n");
	
	char *null_str = NULL;
	const char *string = "1$..!";
	++string;
	ft_printf_test("%c - %s - %p %d - %i - %u - %x %X %%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000);
	ft_printf_test("%c - %s - %p %d - %i - %u - %x %X %%", '\0', "test", (void *)-1, 20, -20, -1, -1, 200000000);
	ft_printf_test("%c - %s - %p %d - %i - %u - %x %X %%", 'c', "", (void *)-1, 20, -20, -1, -1, 200000000);
	ft_printf_test("%i - %s - %p %d - %c - %u - %x %X %%", 20, "", (void *)-1, '\0', -20, -1, -1, 200000000);
	ft_printf_test("%c - %s - %p %d - %i - %u - %x %X %%", 'b', null_str, NULL, 20, -20, -1, -1, 200000000);
	ft_printf_test("%c %s - %p - %d - %i %u - %x - %X %%", '\0', null_str, (void *)0xdeadc0de, 0, (int)-2147483648, -1, -1, 200000000);
	ft_printf_test("\nimprimiendo un símbolo de porcentaje \"%%\", un carácter que debe ser un dolar \"%c\" y la dirección del puntero: %p", *string, &string);
	ft_printf_test("\nhexa del numero '34467797' en minúsculas: %x, y en mayúsculas: %X", 34467797, 34467797);

}
