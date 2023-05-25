/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_txt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:21:11 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/25 16:03:24 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	*ft_strcpy(const char *src, char *dst, size_t dst_start)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && dst_start + i < 4096)
	{
		dst[dst_start + i] = src[i];
		++i;
	}
	dst[dst_start + i] = '\0';
	return (dst_start + i);
}

int ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (0);
		++i;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
		return (1);
	return (0);
}

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
		struc->partial = ft_put_pointer(va_arg(arg, size_t));
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
