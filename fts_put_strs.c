/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_put_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:34:53 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/09 14:13:10 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_string(char *s, int size)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else if (size < 0)
		return (-1);
	return (write(1, s, size));
}
