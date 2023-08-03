/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:02:59 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/03 17:48:32 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *text, ...)
{
	va_list	args;
	t_print	*struc;

	struc = (t_print *)malloc(sizeof(t_print));
	malloc_struc_variables(&struc);
	va_start(args, text);
	while (*text)
	{
		if (*text == '%')
			text = ft_txt_handle_pcnt(++text, &struc, args);
		else
			text = ft_txt_read_until_pcnt(text, &struc);
	}
	va_end(args);
	ft_put_string(struc->print);
	free_struc(&struc);
	return (struc->length);
}


void malloc_struc_variables(t_print **struc)
{
	(*struc)->print = (char *)malloc(MAX_LENGTH * sizeof(char));
	(*struc)->print[0] = '\0';
	(*struc)->real = (char *)malloc(MAX_LENGTH * sizeof(char));
	(*struc)->real[0] = '\0';
}

void free_struc(t_print **struc)
{
	free((*struc)->print);
	free((*struc)->real);
	free((*struc));
}


