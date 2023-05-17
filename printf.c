/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:04:16 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/17 13:21:59 by jarregui         ###   ########.fr       */
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


	const char *string = "1$..!";
	++string;
	printf("\nTEST 4 - %%, caracter y puntero");
	int res41 = printf("\nimprimiendo un símbolo de porcentaje \"%%\", un carácter que debe ser un dolar \"%c\" y el string: %s y el puntero: %p", *string, string, &string);

	return (0);
}