/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_txt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:21:11 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/22 13:44:48 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_txt_find_pcnt(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}

const char	*ft_txt_do_pcnt(const char *text, t_print *struc, va_list arg)
{
	if (*text == '%')
		struc->partial = ft_put_char('%');
	else if (*text == 'c')
		struc->partial = ft_put_char(va_arg(arg, int));
	else if (*text == 's')
		struc->partial = ft_put_string(va_arg(arg, char *));
	else if (*text == 'p')
		struc->partial = ft_put_pointer(va_arg(arg, unsigned long int));
	else if (*text == 'x')
		struc->partial = ft_put_num_base(va_arg(arg, unsigned int), 'x');
	else if (*text == 'X')
		struc->partial = ft_put_num_base(va_arg(arg, unsigned int), 'X');
	else if (*text == 'i')
		struc->partial = ft_put_num_base(va_arg(arg, int), 'd');
	else if (*text == 'd')
		struc->partial = ft_put_num_base(va_arg(arg, int), 'd');
	else
		return (NULL);
	struc->total += struc->partial;
	return (++text);
}

const char	*ft_txt_read_until_pcnt(const char *text, t_print *struc)
{
	int			text_length;
	const char	*next;
	int			next_length;

	struc->partial = 0;
	text_length = ft_len_str(text);
	next = ft_txt_find_pcnt(text);
	next_length = ft_len_str(next);
	struc->partial = text_length - next_length;
	write(1, text, struc->partial);
	struc->total += struc->partial;
	return (next);
}
