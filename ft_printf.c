/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:02:59 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/07 12:28:37 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *text, ...)
{
	va_list	args;
	t_print	*struc;
	int		length;

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
	va_end(args);
	length = ft_put_string(struc->print);
	free_struc(&struc);
	return (length);
}

void	malloc_struc_variables(t_print **struc, const char	*text)
{
	(*struc)->print = (char *)malloc(MAX_LENGTH * sizeof(char));
	(*struc)->print[0] = '\0';
	(*struc)->copy_text = text;
	(*struc)->buffer = (char *)malloc(MAX_LENGTH * sizeof(char));
}

void	free_struc(t_print **struc)
{
	free((*struc)->print);
	free((*struc)->buffer);
	free((*struc));
}
