/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_tests_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:38:45 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/08 00:27:42 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
// #include <stdio.h>//esto es para poder usar el printf real
// #include <limits.h>

// char	*ft_long_str(char *res)
// {
// 	int		i;
// 	int		dest;

// 	i = 0;
// 	dest = 0;
// 	while (i < 30)
// 	{
// 		ft_strcpy("hola ", res, dest);
// 		dest += 5;
// 		i++;
// 	}
// 	res[dest + 1] = '\0';
// 	return (res);
// }

// void	test_00(void)
// {
// 	printf("\n\nTESTS GROUP 0 - CHARACTERS\n");
// 	ft_printf_test("%c", 'a');
// 	ft_printf_test("%c small string", 'a');
// 	ft_printf_test("the char is: %c", 'a');
// 	ft_printf_test("n%cs", 'a');
// 	ft_printf_test("%c%c%c%c%c", 'a', 'i', 'u', 'e', 'o');
// 	ft_printf_test("l%cl%cl%cl%cl%c", 'a', 'i', 'u', 'e', 'o');
// }

// void	test_01(void)
// {
// 	char	*null_str = NULL;
// 	char	*long_str;
// 	char	res[151];

// 	printf("\n\nTESTS GROUP 1 - STRINGS\n");
// 	ft_printf_test("%s", "");
// 	ft_printf_test("this is a %s", "test");
// 	ft_printf_test("this is 1 %s with %s %s", "test", "multiple", "strings");
// 	ft_printf_test("%s%s%s%s", "This ", "is", " an ugly ", "test");
// 	ft_printf_test("%s", "This is a rather simple test.");
// 	ft_printf_test("%s", "-2");
// 	ft_printf_test("%s", "-24");
// 	ft_printf_test("%s", "-stop");
// 	ft_printf_test("%s", "\n\n\"@#~½¬{[]ññöóC€€ßßßßssSSº1ª}");
// 	ft_printf_test("%s", "-0003");
// 	ft_printf_test("%s", "000-0003");
// 	ft_printf_test("%s", "0x42");
// 	ft_printf_test("%s", "0x0000042");
// 	ft_printf_test("some naugty tests: %s", "0000%");
// 	ft_printf_test("some naugty tests: %s", "    %");
// 	ft_printf_test("some naugty tests: %s", "%000");
// 	long_str = ft_long_str(res);
// 	ft_printf_test("%s", long_str);
// 	ft_printf_test("%s", null_str);
// 	ft_printf_test("%s everywhere", null_str);
// 	ft_printf_test("everywhere %s", null_str);
// 	ft_printf_test("%s", "h");
// 	ft_printf_test("t%st%s", "a", "u");
// 	ft_printf_test("%s%s%s%s%s%s", "a", "i", "u", "e", "o", "l");
// 	ft_printf_test("\nvamos con un string nulo --> %s", NULL);
// 	ft_printf_test("\nvamos con un %s en el medio\n", "\"string\"");
// }

// void	test_02(void)
// {
// 	int		test = 42;
// 	int		*ptr = &test;
// 	char	*mallocked = malloc(2);

// 	printf("\n\nTESTS GROUP 2 - POINTERS\n");
// 	ft_printf_test("%p", &test);
// 	ft_printf_test("%p is a virtual memory address", &test);
// 	ft_printf_test("The address of the answer is %p", &test);
// 	ft_printf_test("The address is %p, so what?", &test);
// 	ft_printf_test("A pointer at %p points to %p", &test, &ptr);
// 	ft_printf_test("This %p is a very strange address", (void *)(long int)test);
// 	ft_printf_test("This %p is an address from the heap", mallocked);
// 	free(mallocked);
// 	ft_printf_test("%p", NULL);
// 	ft_printf_test("The (NIL) is mem pos 0, is a non valid address %p ", NULL);
// 	ft_printf_test("This %p is even stranger", (void *)-1);
// 	ft_printf_test("This %p is even stranger", (void *)-2);
// 	ft_printf_test("This %p is even stranger", (void *)-16);
// 	ft_printf_test("This %p is even stranger", (void *)-17);
// 	ft_printf_test("\nLONG_MIN: %p", LONG_MIN);
// 	ft_printf_test("\nLONG_MAX %p", LONG_MAX);
// 	ft_printf_test("\n-1: %p", -1);
// 	ft_printf_test("\n(void *) %p", (void *)-1);
// 	ft_printf_test("\nLONG_MIN: %p", 445645);
// 	ft_printf_test("\nLONG_MAX %p", -456756);
// }

// void	test_03(void)
// {
// 	int	min = -2147483648;
// 	int	max = 2147483647;

// 	printf("\n\nTESTS GROUP 3 - DECIMAL\n");
// 	ft_printf_test("%d", 0);
// 	ft_printf_test("%d", 10);
// 	ft_printf_test("%d, %d", 10, 20);
// 	ft_printf_test("%d%d%d%d", 10, 20, 30, 5);
// 	ft_printf_test("42 - 84 is %d", -42);
// 	ft_printf_test("%d C is the lowest temperature in the universe", -273);
// 	ft_printf_test("\nhola qué tal %d, %d, %d... probando", 1, 2, 3);
// 	ft_printf_test("\nmin int es: \"%d\" y el máx es: \"%d\"", min, max);
// }

// void	test_04(void)
// {
// 	printf("\n\nTESTS GROUP 4 - INT\n");
// 	ft_printf_test("%i", 0);
// 	ft_printf_test("%i", 10);
// 	ft_printf_test("%i, %i", 10, 23);
// 	ft_printf_test("%i%i%i%i%i%i%i", 10, 23, -2, 37, 200, -9999, 977779);
// 	ft_printf_test("%i %i", 2147483647, (int)-2147483648);
// 	ft_printf_test("%iq%i", 21447, -21648);
// }
