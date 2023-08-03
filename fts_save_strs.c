/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_save_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:34:53 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/03 17:47:03 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_char(char c, t_print **struc)
{
	(*struc)->print[(*struc)->length] = c;
	(*struc)->length += 1;
}

void	ft_save_string(char *s, t_print **struc)
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
		position = (*struc)->length;
		while (s[i])
		{
			(*struc)->print[position + i] = s[i];
			i++;
		}
		(*struc)->length += i;
	}
}
