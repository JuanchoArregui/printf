/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_txt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:21:11 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/04 00:20:40 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	*ft_strcpy(const char *src, char *dst, size_t dst_start)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && dst_start + i < MAX_LENGTH)
	{
		dst[dst_start + i] = src[i];
		++i;
	}
	dst[dst_start + i] = '\0';
	return (dst_start + i);
}

int ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (0);
		++i;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
		return (1);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	i;

	length = 0;
	i = 0;
	while (src[length] != '\0')
		++length;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (length);
}