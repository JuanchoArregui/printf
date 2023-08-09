/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_tests_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:38:45 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/09 14:12:04 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../ft_printf.h"
// #include <stdio.h>//esto es para poder usar el printf real

// void	test_05(void)
// {
// 	printf("\n\nTESTS GROUP 5 - UNSIGNED\n");
// 	ft_printf_test("%u", 42);
// 	ft_printf_test("%u", 0);
// 	ft_printf_test("%u", 2147483647);
// 	ft_printf_test("%u", (unsigned int)2147483648);
// 	ft_printf_test("%u", (unsigned int)3147983649);
// 	ft_printf_test("%u", (unsigned int)4294967295);
// 	ft_printf_test("%u exp %u is %u", 2, 32, (unsigned int)4294967295);
// 	ft_printf_test("%u", (unsigned int)429896724);
// 	ft_printf_test("%u%u%u", 0, 32, (unsigned int)4294967295);
// }

// void	test_06(void)
// {
// 	printf("\n\nTESTS GROUP 6 - HEXADECIMAL x\n");
// 	ft_printf_test("%x", 0);
// 	ft_printf_test("%x", 1);
// 	ft_printf_test("%x", 10);
// 	ft_printf_test("%x", 16);
// 	ft_printf_test("%x", 160);
// 	ft_printf_test("%x", 255);
// 	ft_printf_test("%x", 256);
// 	ft_printf_test("%x", 3735929054u);
// 	ft_printf_test("the password is %x", 3735929054u);
// 	ft_printf_test("%x is the definitive answer", 66u);
// 	ft_printf_test("this is the real number: %x", -1u);
// }

// void	test_07(void)
// {
// 	printf("\n\nTESTS GROUP 7 - HEXADECIMAL X\n");
// 	ft_printf_test("%X", 0);
// 	ft_printf_test("%X", 1);
// 	ft_printf_test("%X", 10);
// 	ft_printf_test("%X", 16);
// 	ft_printf_test("%X", 160);
// 	ft_printf_test("%X", 255);
// 	ft_printf_test("%X", 256);
// 	ft_printf_test("%X", (unsigned int)3735929054);
// 	ft_printf_test("the password is %X", (unsigned int)3735929054);
// 	ft_printf_test("%X is the definitive answer", (unsigned int)66);
// 	ft_printf_test("this is the real number: %X", (unsigned int)-1);
// }

// void	test_08(void)
// {
// 	printf("\n\nTESTS GROUP 8 - PERCENTAGE\n");
// 	ft_printf_test("%%");
// 	ft_printf_test("100%%");
// 	ft_printf_test("%%p is how you print a pointer in printf");
// 	ft_printf_test("the '%%%%' is used to print a %% in printf");
// 	ft_printf_test("%%%%%%%%%%%%%%%%");
// 	ft_printf_test("%%c%%s%%p%%d%%i%%u%%x%%X%%");
// 	ft_printf_test("\nªº!@~#=?¿\n12345\n6789\"\'''öu'o'eèü¢``_%% %%");
// }

// void	test_09(void)
// {
// 	char		*null_str = NULL;
// 	const char	*string = "1$..!";

// 	printf("\n\nTESTS GROUP 9 - MIX\n");
// 	++string;
// 	ft_printf_test("%c - %s - %p %d", 'a', "test", (void *)0xdeadc0de, -20);
// 	ft_printf_test("%i - %u - %x %X %%", -1, 20, -1, 200000000);
// 	ft_printf_test("%c - %s - %p", 'c', "", (void *)-1);
// 	ft_printf_test("%d - %i - %u - %x %X %%", 20, -20, -1, -1, 200000000);
// 	ft_printf_test("%i - %s - %p", 20, "", (void *)-1);
// 	ft_printf_test("%d - %c - %u - %x %X %%", '\0', -20, -1, -1, 200000000);
// 	ft_printf_test("%c - %s - %p", 'b', null_str, NULL);
// 	ft_printf_test("%d - %i - %u - %x %X %%", 20, -20, -1, -1, 200000000);
// 	ft_printf_test("%s - %p - %d", null_str, (void *)0xdeadc0de, 0);
// 	ft_printf_test("%i %u - %x - %X %%", (int)-2147483648, -1, -1, 200000000);
// 	ft_printf_test("\nporcentaje \"%%\", $: \"%c\",ptr: %p", *string, &string);
// 	ft_printf_test("\nhexa en minús: %x, y en mayús: %X", 34467797, 34467797);
// }

// void	test_10(void)
// {
// 	printf("\n\nTESTS GROUP 10 - FUCKING ZEROES IN THE MIDDLE!!\n");
// 	ft_printf_test("%c%c%c%c", '0', 0, '1', '2');
// 	ft_printf_test("zero %c %c %c ", '0', 0, '1');
// 	ft_printf_test("l%cl%cl%cl%cl%c", '\0', '\0', '\0', 'e', '\0');
// 	ft_printf_test("the char is: %c", '\0');
// 	ft_printf_test("%c small string", '\0');
// 	ft_printf_test("%c%c%c*", '\0', '1', 1);
// 	ft_printf_test("%c - %s - %p - %d - %i", '\0', "test", (void *)-1, 20, -20);
// 	ft_printf_test("%c - %p - %d", '\0', (void *)0xdeadc0de, 0);
// }
