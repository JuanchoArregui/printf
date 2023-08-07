/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:38:45 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/07 13:34:07 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
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
	length = ft_len_str(struc->print);
	va_end(args);
	struc->length = length;
	va_start(args, text);
	vsprintf(buffer, struc->copy_text, args);
	va_end(args);
	ft_strcpy(buffer, struc->buffer, 0);
	ft_check_test(&struc);
	free_struc(&struc);
	return (length);
}

void	ft_check_test(t_print **struc)
{
	int	check;
	int	error;

	if ((*struc)->length == ft_len_str((*struc)->buffer))
		printf("[ \033[32mOK\033[0m");
	else
	{
		printf("[ \033[31mKO\033[0m");
		error = 1;
	}
	check = ft_strcmp((*struc)->print, (*struc)->buffer);
	if (check == 1)
		printf(" - \033[32mOK\033[0m ]     ");
	else
	{
		printf(" - \033[31mKO\033[0m ]     ");
		error = 1;
	}
	if (error == 1)
	{
		printf("\nPrinted at ft_printf: %s", (*struc)->print);
		printf("\nReturned at ft_printf: %i", (*struc)->length);
		printf("\nTo be printed at printf: %s", (*struc)->buffer);
		printf("\nTo be returned at printf: %i\n", ft_len_str((*struc)->buffer));
	}
}

int	main(void)
{
	test_00();
	test_01();
	test_02();
	test_03();
	test_04();
	test_05();
	test_06();
	test_07();
	test_08();
	test_09();
	return (0);
}
*/
