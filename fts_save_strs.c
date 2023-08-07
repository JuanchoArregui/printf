/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_save_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:34:53 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/07 16:37:41 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_char(char c, t_print **struc)
{
	(*struc)->print[(*struc)->position] = c;
	(*struc)->print[(*struc)->position + 1] = '\0';
	(*struc)->position += 1;
}

void	ft_save_string(char *s, t_print **struc)
{
	int		i;

	if (!s)
	{
		ft_save_string("(null)", struc);
	}
	else
	{
		i = 0;
		while (s[i])
		{
			(*struc)->print[(*struc)->position + i] = s[i];
			i++;
		}
		(*struc)->print[(*struc)->position + i] = '\0';
		(*struc)->position += i;
	}
}
