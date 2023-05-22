/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_put_nums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:34:53 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/22 10:39:54 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_basechars(char base_type)
{
	if (base_type == 'X')
		return ("0123456789ABCDEF");
	else if (base_type == 'x')
		return ("0123456789abcdef");
	else if (base_type == 'd')
		return ("0123456789");
	return (NULL);
}

unsigned long int	ft_get_base(char base_type)
{
	if (base_type == 'X')
		return (16);
	else if (base_type == 'x')
		return (16);
	else if (base_type == 'd')
		return (10);
	return (0);
}

int	ft_put_pointer(unsigned long int ptr)
{
	int	partial;

	write(1, "0x", 2);
	partial = ft_put_num_base(ptr, 'x');
	return (partial + 2);
}

int	ft_put_num_base(unsigned long int nb, char base_type)
{
	char				*basechars;
	unsigned long int	base;
	int					res[100];
	int					i;
	int					partial;

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
	partial = i + 1;
	while (i >= 0)
	{
		ft_put_char(res[i]);
		i--;
	}
	return (partial);
}

// int	ft_puthexa(unsigned long int nb, int upper)
// {
// 	char	*hexa;
// 	int		res[100];
// 	int		i;
// 	int		partial;

// 	if (upper)
// 		hexa = "0123456789ABCDEF";
// 	else
// 		hexa = "0123456789abcdef";
// 	i = 0;
// 	while (nb > 16)
// 	{
// 		res[i] = hexa[nb % 16];
// 		nb /= 16;
// 		i++;
// 	}
// 	res[i] = hexa[nb];
// 	partial = i + 1;
// 	while (i >= 0)
// 	{
// 		ft_put_char(res[i]);
// 		i--;
// 	}
// 	return (partial);
// }

// void	ft_putnumber(int nb)
// {
// 	if (nb < 0)
// 	{
// 		if (nb == -2147483648)
// 			ft_putstring("-2147483648");
// 		else
// 		{
// 			ft_put_char('-');
// 			ft_putnumber(-nb);
// 		}
// 	}
// 	else if (nb > 10)
// 	{
// 		ft_putnumber(nb / 10);
// 		ft_putnumber(nb % 10);
// 	}
// 	else
// 	{
// 		ft_put_char(nb + 48);
// 	}
// }