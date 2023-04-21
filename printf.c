/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:04:16 by jarregui          #+#    #+#             */
/*   Updated: 2023/04/21 13:10:03 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	char	*strnum;
	int		num;

	num= 1234;
	strnum = "92233720";

	printf("\nstrnum: %s", strnum);
	printf("\nnumber: %d", num);
	printf("\nHello world");
	return (0);
}