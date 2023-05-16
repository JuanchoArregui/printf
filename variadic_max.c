/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:02:59 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/16 11:37:45 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h> //this for variadic functions
#include <string.h> //this for handeling strings

//nice viedo about variadic functions:
//https://www.youtube.com/watch?v=3iX9a_l9W9Y

int		max(int num_args, ...);
void	print(char *placeholders, ...);

int	main(void)
{
	int	max_num;

	max_num = max(4, 9, 16, 2, 27);
	printf("Max num is: %d\n\n\n", max_num);
	return (0);
}

int	max(int num_args, ...)
{
	va_list	args;
	int		i;
	int		x;
	int		max;

	i = 0;
	max = 0;
	va_start(args, num_args);

	while (i < num_args)
	{
		x = va_arg(args, int);
		printf("arg %d - x: %d\n", i, x);
		if (x > max)
			max = x;
		i++;
	}
	printf("\n");
	va_end(args);

	return (max);
}
