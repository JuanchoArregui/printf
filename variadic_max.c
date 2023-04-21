/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:02:59 by jarregui          #+#    #+#             */
/*   Updated: 2023/04/21 15:49:50 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h> //this for variadic functions
#include <string.h> //this for handeling strings

//nice viedo: https://www.youtube.com/watch?v=3iX9a_l9W9Y

int		max(int num_args, ...);
void	print(char *placeholders, ...);

int	main(void)
{
	int max_num;

	max_num = max(4, 5, 6, 2, 27);
	printf("Max num is: %d\n", max_num);

	print("dfdf", 3, 1.1, 6, 77.7);

	return (0);
}

int	max(int num_args, ...)
{
	va_list	args;
	int		x;
	int		max;

	max = 0;
	va_start(args, num_args);

	for (int i = 0; i < num_args; i++)
	{
		x = va_arg(args, int);
		printf("arg %d - x: %d\n", i, x);
		if (x > max) max = x;
	}
	printf("\n");
	va_end(args);

	return (max);
}

void	print(char *placeholders, ...)
{
	va_list	args;
	int		x;
	double	dbl;
	int		num_args;

	num_args = strlen(placeholders);
	va_start(args, placeholders);

	for (int i = 0; i < num_args; i++)
	{
		if (placeholders[i] == 'd')
		{
			x = va_arg(args, int);
			printf("%%d: %d\n", x);
		}
		else if (placeholders[i] == 'f')
		{
			dbl = va_arg(args, int);
			printf("%%f: %f\n", dbl);
		}
	}
	printf("\n");
	va_end(args);
}