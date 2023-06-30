/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_save_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:34:53 by jarregui          #+#    #+#             */
/*   Updated: 2023/06/30 01:02:51 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_char(char c, t_print *struc)
{
	struc->print[struc->length] = c;
	struc->length += 1;

	printf("\ft_save_char -->char: %c", c);
	printf("\ft_save_char --> struc->print: %s", struc->print);
	printf("\ft_save_char --> struc->length: %i", struc->length);
}

void	ft_save_string(char *s, t_print *struc)
{
	int	i;
	int	position;

	if (!s)
	{
		ft_save_string("(null)", struc);
	}
	else
	{
		i = 0;
		position = struc->length;
		while (s[i])
		{
			struc->print[position + i] = s[i];
			i++;
		}
		struc->length += i;
	}
}
