/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:03:18 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/06 19:26:14 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MAX_LENGTH 4096

# include <unistd.h>//this is for using write
# include <stdarg.h>//this is for variadic functions
# include <stdlib.h>//this is for using malloc

typedef struct s_print
{
	char		*print;
	int			position;
	int			length;
	const char	*copy_text;
	char		*buffer;
}	t_print;

/* -------- ft_printf.c */
/* -------- Main PRINTF function */
int			ft_printf(const char *text, ...);
void		malloc_struc_variables(t_print **struc, const char	*text);
void		free_struc(t_print **struc);
/* -------- fts_handling_main_txt.c */
/* -------- Handling the text to print */
const char	*ft_txt_read_until_pcnt(const char *text, t_print **struc);
const char	*ft_txt_handle_pcnt(const char *text, t_print **struc, va_list arg);
/* -------- fts_save_strs.c */
/* -------- Saving characters and string to be printed at structure */
void		ft_save_char(char c, t_print **struc);
void		ft_save_string(char *s, t_print **struc);
/* -------- fts_save_nums.c */
/* -------- Saving numbers to be printed at structure */
char		*ft_get_basechars(char base_type);
int			ft_get_base(char base_type);
void		ft_save_pointer(void *ptr, t_print **struc);
void		ft_save_negative_pointer(long int nb, t_print **struc);
void		ft_save_num_base(long int nb, char base_type, t_print **struc);
/* -------- fts_put_strs.c */
/* -------- Printing String functions */
int			ft_put_char(char c);
int			ft_put_string(char *s);
// /* -------- fts_len.c  */
int			ft_len_str(const char *s);
int			ft_len_int(int nb, char c);
// /* -------- fts_str.c  */
int			ft_strcmp(const char *str1, const char *str2);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strcpy(const char *src, char *dst, size_t dst_start);
/* ---------- fts_test_0.c Tests */
void		test_00(void);
void		test_01(void);
void		test_02(void);
void		test_03(void);
void		test_04(void);
void		test_05(void);
void		test_06(void);
void		test_07(void);
void		test_08(void);
void		test_09(void);
/* ---------- fts_test.c Testing functions */
int			ft_printf_test(const char *text, ...);
void		ft_check_test(t_print **struc);
int			main(void);

#endif