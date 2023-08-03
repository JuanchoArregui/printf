/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_save_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:34:53 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/03 13:56:07 by juancho          ###   ########.fr       */
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

int	ft_get_base(char base_type)
{
	if (base_type == 'X')
		return (16);
	else if (base_type == 'x')
		return (16);
	else if (base_type == 'd' || base_type == 'i' )
		return (10);
	return (0);
}

void	ft_save_pointer(size_t ptr, t_print **struc)
{
	ft_save_string("0x", struc);
	ft_save_num_base(ptr, 'x', struc);
}

void	ft_save_num_base(long int nb, char base_type, t_print **struc)
{
	
	printf("\nft_save_num_base --> base_type: %c", base_type);
	printf("\nft_save_num_base --> base_type: %i", (*struc)->length);

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






// int	ft_puthexa(size_t nb, int upper)
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