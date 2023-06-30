/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_handling_main_txt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:21:11 by jarregui          #+#    #+#             */
/*   Updated: 2023/06/30 01:24:11 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_txt_handle_pcnt(const char *text, t_print *struc, va_list args)
{
	if (*text == '%')
		ft_save_char('%', struc);
	else if (*text == 'c')
		ft_save_char(va_arg(args, int), struc);
	else if (*text == 's')
		ft_save_string(va_arg(args, char *), struc);
	else if (*text == 'p')
		ft_save_pointer(va_arg(args, size_t), struc);
	else if (*text == 'x')
		ft_save_num_base(va_arg(args, unsigned int), 'x', struc);
	else if (*text == 'X')
		ft_save_num_base(va_arg(args, unsigned int), 'X', struc);
	else if (*text == 'i')
		ft_save_num_base(va_arg(args, int), 'i', struc);
	else if (*text == 'd')
		ft_save_num_base(va_arg(args, int), 'd', struc);
	else
		return (NULL);
	return (++text);
}

const char	*ft_txt_read_until_pcnt(const char *text, t_print *struc)
{
	int	i;

	i = 1;
	while (*text)
	{
		printf("\ni: %i", i);
		
		if (*text == '%')
			return ((char *)text);
		ft_save_char(*text, struc);

		printf("\n");

		text++;

		i++;
	}
	return ((char *)text);

}
