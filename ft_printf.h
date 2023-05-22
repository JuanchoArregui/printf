/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:03:18 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/22 10:41:16 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>//FORBIDDEN. just for testing purposes
# include <unistd.h>//this is for using write
# include <stdarg.h>//this is for variadic functions

typedef struct s_print
{
	int	partial;
	int	total;
}	t_print;

/* ---------- ft_printf.c Main function --------------------- */
int					ft_printf(const char *text, ...);
int					main(void);
/* ---------- fts_len.c  --------------------- */
unsigned long		ft_len_str(const char *s);
int					ft_len_int(int nb, char c);
/* ---------- fts_put_nums.c Printing Numbers functions --------------------- */
char				*ft_get_basechars(char base_type);
unsigned long int	ft_get_base(char base_type);
int					ft_put_pointer(unsigned long int ptr);
int					ft_put_num_base(unsigned long int nb, char base_type);
/* ---------- fts_put_strs.c Printing String functions --------------------- */
int					ft_put_char(char c);
int					ft_put_string(char *s);
/* ---------- fts_txt.c Handling the text to print --------------------- */
const char			*ft_txt_find_pcnt(const char *s);
const char			*ft_txt_read_until_pcnt(const char *text, t_print *struc);
const char			*ft_txt_do_pcnt(const char *text, t_print *struc, va_list arg);

#endif