/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:03:18 by jarregui          #+#    #+#             */
/*   Updated: 2023/07/13 15:34:42 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MAX_LENGTH 4096

# include <unistd.h>//this is for using write
# include <stdarg.h>//this is for variadic functions
# include <stdlib.h>//this is for using malloc


//BOORRAR ESTO Y DEJARLO SOLO EN TESTING
//BOORRAR ESTO Y DEJARLO SOLO EN TESTING
//BOORRAR ESTO Y DEJARLO SOLO EN TESTING
//BOORRAR ESTO Y DEJARLO SOLO EN TESTING
# include <stdio.h>

typedef struct s_print
{
	char	*print;
	int		length;
}	t_print;

/* -------- ft_printf.c */
/* -------- Main function */
int			ft_printf(const char *text, ...);
char		*ft_vsnprintf(t_print *struc, const char *text, va_list args);
/* -------- fts_handling_main_txt.c */
/* -------- Handling the text to print */
const char	*ft_txt_read_until_pcnt(const char *text, t_print *struc);
const char	*ft_txt_handle_pcnt(const char *text, t_print *struc, va_list arg);
/* -------- fts_save_strs.c */
/* -------- Saving characters and string to be printed at structure */
void		ft_save_char(char c, t_print *struc);
void		ft_save_string(char *s, t_print *struc);
/* -------- fts_save_nums.c */
/* -------- Saving numbers to be printed at structure */
char		*ft_get_basechars(char base_type);
int			ft_get_base(char base_type);
void		ft_save_pointer(size_t ptr, t_print *struc);
void		ft_save_num_base(size_t nb, char base_type, t_print *struc);
/* -------- fts_put_strs.c */
/* -------- Printing String functions */
int			ft_put_char(char c);
int			ft_put_string(char *s);



// /* -------- fts_len.c  */
// size_t		ft_len_str(const char *s);
// int			ft_len_int(int nb, char c);




/* ---------- fts_test.c Testing functions */
void		ft_test(const char *text, ...);
int			main(void);

#endif