/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_save_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:34:53 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/07 00:44:10 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>//esto es para poder usar el printf real


char	*ft_get_basechars(char base_type)
{
	if (base_type == 'X')
		return ("0123456789ABCDEF");
	else if (base_type == 'x')
		return ("0123456789abcdef");
	else if (base_type == 'f')
		return ("ffffffffffffffff");
	else if (base_type == 'F')
		return ("0fedcba987654321");
	else
		return ("0123456789");
}

int	ft_get_base(char base_type)
{
	if (base_type == 'X')
		return (16);
	else if (base_type == 'x')
		return (16);
	else
		return (10);
}

void	ft_save_pointer(void *ptr, t_print **struc)
{
	if (ptr == NULL)
	{
		ft_save_string("(nil)", struc);
	}
	else
	{
		ft_save_string("0x", struc);
		if ((long int)ptr < 0)
			ft_save_negative_pointer(-1 * (long int)ptr, struc);
		else
			ft_save_num_base((long int)ptr, 'x', struc);
	}
}

void	ft_save_negative_pointer(long int nb, t_print **struc)
{
	char	res[17];
	char	*basechars;
	char	buffer[17];
	int		i;
	int		base;
	int		resto;


	resto = -1;
	ft_strcpy(ft_get_basechars('f'), res, 0);
	basechars = ft_get_basechars('F');
	base = 16;
	i = 0;
	while (nb >= base)
	{	
		resto = nb % base;
		buffer[i] = basechars[resto];
		nb /= base;
		i++;
	}
	if( resto == -1 || (i > 0 && resto == 0)) 
		buffer[i] = basechars[nb];
	else
		buffer[i] = basechars[nb + 1];
	buffer[i + 1] = '\0';
	while (i >= 0)
	{
		res[15 - i] = buffer[i];
		i--;
	}
	ft_save_string(res, struc);
}

void	ft_save_num_base(long int nb, char base_type, t_print **struc)
{
	char		*basechars;
	int			base;
	int			res[100];
	int			i;

	if (nb < 0)
	{
		ft_save_char('-', struc);
		nb = -1 * nb;
	}
	basechars = ft_get_basechars(base_type);
	base = ft_get_base(base_type);
	i = 0;
	while (nb >= base)
	{
		res[i] = basechars[nb % base];
		nb /= base;
		i++;
	}
	res[i] = basechars[nb];
	while (i >= 0)
	{
		ft_save_char(res[i], struc);
		i--;
	}
}
