# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 13:58:00 by jarregui          #+#    #+#              #
#    Updated: 2023/08/09 18:32:14 by jarregui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES DECLARATION:
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address
ARFLAGS		=	rcs
NAME		=	libftprintf.a
RM			=	/bin/rm -f
EXEC_NAME	=	a.out

SRCS		=	ft_printf.c \
				fts_get.c \
				fts_handling_main_txt.c \
				fts_len.c \
				fts_put_strs.c \
				fts_save_nums.c \
				fts_save_strs.c \
				fts_str.c \


# SRCS_BONUS	=	fts_bonus.c

SRCS_TEST	=	./tests/fts_test.c \
				./tests/fts_tests_a.c \
				./tests/fts_tests_b.c \

OBJS		=	${SRCS:.c=.o}
# OBJS_BONUS	=	${SRCS_BONUS:.c=.o}
OBJS_TEST	=	${SRCS_TEST:.c=.o}

# RULES DECLARATION:
all:			${NAME}

${NAME}:		${OBJS}
					ar -rc ${NAME} ${OBJS}
					ranlib ${NAME}

clean:
				${RM} ${OBJS} ${OBJS_BONUS} ${OBJS_TEST} ${EXEC_NAME}

fclean:			clean
					${RM} ${NAME}

test:			${OBJS} ${OBJS_TEST}
				${CC} ${CFLAGS} -o ${EXEC_NAME} ${OBJS} ${OBJS_TEST}
 
re:				fclean all

.PHONY:			all clean fclean re bonus test