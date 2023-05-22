/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_put_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:34:53 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/22 10:39:58 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_string(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		i = 0;
		while (s[i])
		{
			ft_put_char(s[i]);
			i++;
		}
		return (i);
	}
}
