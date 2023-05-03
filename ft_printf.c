/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:02:59 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/03 17:26:04 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h> //this for variadic functions
#include <string.h> //this for handeling strings

int				ft_printf(char const *placeholders, ...);

typedef struct s_print
{
	va_list	args;
	int		width;
	int		length;

	int		prc;        // precision              
	int		zero;       // zero padding               
	int		pnt;        // .     
	int		dash;       // -               
	int		tl;         // total_length (return value)              
	int		sign;       // pos or neg number               
	int		is_zero;    // is number zero                 
	int		perc;       // %               
	int		sp;         // space flag ' '            
}	t_print;

int	main(void)
{
	ft_printf("hola este es mi printf, aquí va un número:%c y aquí un string:%s", 666, 'esto es un string');
	return (0);
}



int	ft_printf(char const *placeholders, ...)
{
	va_list	args;
	t_print	my_struc;

	my_struc.width = 0;
	my_struc.length = 0;
	// int		i;
	// int		x;
	// double	dbl;
	// int		num_args;

	va_start(args, placeholders);
	while (*placeholders)
	{
		if (*placeholders == '%')
			printf("\nHemos encontrado un%%!!!!\n");
		else
			printf("%s", placeholders);
		placeholders++;
	}
	printf("\n");
	va_end(args);
	
	return (0);
}