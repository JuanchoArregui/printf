/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:34:53 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/07 14:28:45 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
