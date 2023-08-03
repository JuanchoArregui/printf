/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:38:45 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/04 00:28:35 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>//esto es para poder usar el printf real

int	ft_printf_test(const char *text, ...)
{
	va_list		args;
	t_print		*struc;
	int			length;
	char		buffer[MAX_LENGTH];

	struc = (t_print *)malloc(sizeof(t_print));
	malloc_struc_variables(&struc, text);
	va_start(args, text);
	while (*text)
	{
		if (*text == '%')
			text = ft_txt_handle_pcnt(++text, &struc, args);
		else
			text = ft_txt_read_until_pcnt(text, &struc);
	}
	length = ft_put_string(struc->print);
	va_end(args);

	va_start(args, text);
	vsprintf(buffer, struc->copy_text, args);
	va_end(args);
	ft_strcpy(buffer, struc->buffer, 0);

	printf("\nstruc->position: %i", struc->position);
	printf("\nlength: %i", length);
	printf("\nBuffer: %s", buffer);
	printf("\nBuffer length: %i", ft_len_str(buffer));

	free_struc(&struc);
	return (length);
}

void	test_00(void)
{
 	char character = 'k';
    char string[] = "Esto es un string";

	ft_printf("\n\nTEST 00 - impreme un CARACTER y un STRING");
	// printf("\nEl carácter es: \"%c\" y el string es: \"%s\"", character, string);
	// ft_printf("\nEl carácter es: \"%c\" y el string es: \"%s\"", character, string);
	ft_printf_test("\nEl carácter es: \"%c\" y el string es: \"%s\"", character, string);
}

void	test_01(void)
{
 	int min = -2147483648;
 	int max = 2147483647;

	printf("\n\nTEST 01 - variables tipo INT min y max");
	printf("\nEl entéro mínimo es: \"%i\" y el máximo es: \"%i\"", min, max);
	ft_printf_test("\nEl entéro mínimo es: \"%i\" y el máximo es: \"%i\"", min, max);

}



// 	//Revisar esta parte y ver si asi tiene sentido
// 	//si hay que modificar la función s_ft_printf
// 	//Y si sería mejor hacerlo con un puntero, y reservarle memoria con malloc
// 	ft_strlcpy(test.out_ft_pf, s_ft_printf(text, args), size_t size);



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
	// printf("El valor máximo de int es: %d\n", INT_MAX);
    // printf("El valor mínimo de int es: %d\n", INT_MIN);
	test_00();
	// test_01();


	// length = ft_printf("hola caracola");
	// printf("\nreturned length: %i", length);
	// length = ft_printf("");
	// printf("\nreturned length: %i", length);
	// char kk[2];
	// length = printf("%s", kk);
	// printf("\nreturned length: %i", length);

	

    

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

