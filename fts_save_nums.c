/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_save_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:34:53 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/05 04:59:57 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_basechars(char base_type)
{
	if (base_type == 'X')
		return ("0123456789ABCDEF");
	else if (base_type == 'x')
		return ("0123456789abcdef");
	else
		return ("0123456789");
	return (NULL);
}

int	ft_get_base(char base_type)
{
	if (base_type == 'X')
		return (16);
	else if (base_type == 'x')
		return (16);
	else
		return (10);
	return (0);
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
		ft_save_num_base((long int)ptr, 'x', struc);
	}
}

void	ft_save_num_base(long int nb, char base_type, t_print **struc)
{
	char		*basechars;
	long int	base;
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
	while (nb > base)
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
