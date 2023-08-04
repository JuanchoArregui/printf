/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:38:45 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/04 02:31:50 by juancho          ###   ########.fr       */
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
	int check;

	if ((*struc)->length == ft_len_str((*struc)->buffer))
		printf("\n\033[32mLength comparison OK\033[0m");
	else
		printf("\n\033[31mLength comparison Error\033[0m ft_printf: %i printf: %i", (*struc)->length, ft_len_str((*struc)->buffer));
	check = ft_strcmp((*struc)->print, (*struc)->buffer);
	if (check == 1)
		printf("\n\033[32mString comparison OK\033[0m");
	else
	{
		printf("\n\033[31mString comparison Error\033[0m ft_printf: %i printf: %i", (*struc)->length, ft_len_str((*struc)->buffer));
		printf("\nft_printf: %s", (*struc)->print);
		printf("\nprintf: %s", (*struc)->buffer);
	}
}

int	main(void)
{
	test_00();
	test_01();
	test_02();
	test_03();
	return (0);
}
