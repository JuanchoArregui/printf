/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:03:18 by jarregui          #+#    #+#             */
/*   Updated: 2023/05/25 16:01:13 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>//this is for using write
# include <stdarg.h>//this is for variadic functions

typedef struct s_print
{
	char	partial[4096];
	char	total[4096];
}	t_print;

/* ---------- ft_printf.c Main function --------------------- */
int			ft_printf(const char *text, ...);
char		*s_ft_printf(const char *text, ...);
/* ---------- fts_len.c  --------------------- */
size_t		ft_len_str(const char *s);
int			ft_len_int(int nb, char c);
/* ---------- fts_put_nums.c Printing Numbers functions --------------------- */
char		*ft_get_basechars(char base_type);
size_t		ft_get_base(char base_type);
int			ft_put_pointer(size_t ptr);
int			ft_put_num_base(size_t nb, char base_type);
/* ---------- fts_put_strs.c Printing String functions --------------------- */
int			ft_put_char(char c);
int			ft_put_string(char *s);
/* ---------- fts_txt.c Handling the text to print --------------------- */
const char	*ft_txt_find_pcnt(const char *s);
const char	*ft_txt_read_until_pcnt(const char *text, t_print *struc);
const char	*ft_txt_do_pcnt(const char *text, t_print *struc, va_list arg);
/* ---------- fts_test.c Testing functions --------------------- */
int			main(void);

#endif