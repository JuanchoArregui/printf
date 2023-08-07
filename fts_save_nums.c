/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_save_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:34:53 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/07 16:24:10 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_pointer(void *ptr, t_print **struc)
{
	if (ptr == NULL)
	{
		ft_save_string("0x0", struc);
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

void	ft_set_neg_ptr(t_neg_ptr	*neg_ptr)
{
	neg_ptr->resto = -1;
	neg_ptr->basechars = ft_get_basechars('F');
	neg_ptr->base = 16;
	neg_ptr->i = 0;
}

void	ft_save_negative_pointer(long int nb, t_print **struc)
{
	t_neg_ptr	neg_ptr;
	char		res[17];

	ft_set_neg_ptr(&neg_ptr);
	ft_strcpy(ft_get_basechars('f'), res, 0);
	while (nb >= neg_ptr.base)
	{	
		neg_ptr.resto = nb % neg_ptr.base;
		neg_ptr.buffer[neg_ptr.i] = neg_ptr.basechars[neg_ptr.resto];
		nb /= neg_ptr.base;
		neg_ptr.i++;
	}
	if (neg_ptr.resto == -1 || (neg_ptr.i > 0 && neg_ptr.resto == 0))
		neg_ptr.buffer[neg_ptr.i] = neg_ptr.basechars[nb];
	else
		neg_ptr.buffer[neg_ptr.i] = neg_ptr.basechars[nb + 1];
	neg_ptr.buffer[neg_ptr.i + 1] = '\0';
	while (neg_ptr.i >= 0)
	{
		res[15 - neg_ptr.i] = neg_ptr.buffer[neg_ptr.i];
		neg_ptr.i--;
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
