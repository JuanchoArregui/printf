/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:02:59 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/25 14:31:33 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*s_ft_printf(const char *text, ...)
{
	va_list	args;
	t_print	struc;

	struc.partial = "";

	ft_strcpy("", struc.partial)


	struc.total = "";
	va_start(args, text);
	while (*text)
	{
		if (*text == '%')
			text = ft_txt_do_pcnt(++text, &struc, args);
		else
			text = ft_txt_read_until_pcnt(text, &struc);
	}
	va_end(args);
	return (struc.total);
}

int	ft_printf(const char *text, ...)
{
	char	*str_to_be_printed;
	va_list	args;

	va_start(args, text);
	str_to_be_printed = s_ft_print(text, args);
	va_end(args);
	return (ft_put_string(str_to_be_printed));
}

