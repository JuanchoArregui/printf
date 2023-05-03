/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:02:59 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/03 16:56:30 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h> //this for variadic functions
#include <string.h> //this for handeling strings

int				print(char *placeholders, ...);

int	main(void)
{
	print("dfdf", 3, 1.1, 6, 77.7);
	return (0);
}



int	ft_printf(char const *placeholders, ...)
{
	va_list	args;
	int		i;
	int		x;
	double	dbl;
	int		num_args;

	num_args = strlen(placeholders);
	va_start(args, placeholders);
	i = 0;

	while (i < num_args)
	{
		if (placeholders[i] == 'd')
		{
			x = va_arg(args, int);
			printf("%%d: %d", x);
		}
		else if (placeholders[i] == 'f')
		{
			dbl = va_arg(args, int);
			printf("%%f: %f", dbl);
		}
		printf("\n");
		i++;
	}
	printf("\n");
	va_end(args);
}