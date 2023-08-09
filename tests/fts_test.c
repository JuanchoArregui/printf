/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:38:45 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/09 14:51:00 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../ft_printf.h"
// #include <stdio.h>//esto es para poder usar el printf real

// int	ft_printf_test(const char *text, ...)
// {
// 	va_list		args;
// 	t_print		*struc;
// 	int			length;
// 	char		buffer[MAX_LENGTH];

// 	struc = (t_print *)malloc(sizeof(t_print));
// 	if (!struc)
// 		return (-1);
// 	if (!malloc_struc_variables(&struc, text))
// 		return (free(struc), -1);
// 	va_start(args, text);
// 	while (*text)
// 	{
// 		if (*text == '%')
// 			text = ft_txt_handle_pcnt(++text, &struc, args);
// 		else
// 			text = ft_txt_read_until_pcnt(text, &struc);
// 	}
// 	length = struc->position;
// 	va_end(args);

// 	//esto guarda en el buffer el string que daría printf
// 	va_start(args, text);
// 	vsprintf(buffer, struc->copy_text, args);
// 	va_end(args);

// 	//esto guarda en struc->printf_len el int que daría printf
// 	va_start(args, text);
// 	//Redirigir stdout a un archivo temporal
// 	FILE *temp_stdout = freopen("temp.txt", "w", stdout);
// 	//Imprimir utilizando vprintf y la lista de argumentos preparada
// 	struc->printf_len = vprintf(struc->copy_text, args);
// 	fclose(temp_stdout);  // Cerrar el archivo temporal
// 	remove("temp.txt");  // Eliminar el archivo temporal
// 	stdout = freopen("/dev/tty", "w", stdout);  // Restaurar stdout
// 	va_end(args);

// 	//copiamos el buffer pero con nuestra función que no para en el primer 0....
// 	//...si no que sigue hasta el size que le digamos
// 	ft_strcpy_size(buffer, struc->printf_str, struc->printf_len);
// 	ft_check_test(&struc);
// 	free_struc(&struc);
// 	return (length);
// }

// void	ft_check_test(t_print **struc)
// {
// 	int	check;
// 	int	error;
// 	int	l;

// 	error = 0;
// 	l = (*struc)->position;
// 	if ((*struc)->position == (*struc)->printf_len)
// 	{
// 		printf("[ \033[32mOK\033[0m");
// 		check = ft_strcmp_size((*struc)->print, (*struc)->printf_str, l);
// 		if (check == 1)
// 			printf(" - \033[32mOK\033[0m ]     ");
// 		else
// 		{
// 			printf(" - \033[31mKO\033[0m ]     ");
// 			error = 1;
// 		}
// 	}
// 	else
// 	{
// 		printf("[ \033[31mKO\033[0m ]");
// 		error = 1;
// 	}
// 	if (error == 1)
// 	{
// 		printf("\nPrinted at ft_printf: %s", (*struc)->print);
// 		printf("\nReturned at ft_printf: %i", (*struc)->position);
// 		printf("\nTo be printed at printf: %s", (*struc)->printf_str);
// 		printf("\nTo be returned at printf: %i\n", (*struc)->printf_len);
// 	}
// }

// int	main(void)
// {
// 	// int kk = printf("\nel 50%");
// 	// int kk = printf("12345%");
// 	// printf("\n%d", kk);

// 	int kk = printf("%hhhhola");
// 	printf("\n%d", kk);

// 	// test_0();
// 	// test_00();
// 	// test_01();
// 	// test_02();
// 	// test_03();
// 	// test_04();
// 	// test_05();
// 	// test_06();
// 	// test_07();
// 	// test_08();
// 	// test_09();
// 	// test_10();
// 	return (0);
// }
