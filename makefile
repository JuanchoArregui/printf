# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 13:58:00 by jarregui          #+#    #+#              #
#    Updated: 2023/05/22 11:14:30 by jarregui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# VARIABLES DECLARATION:
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
ARFLAGS		=	rcs
NAME		=	libftprintf.a
RM			=	/bin/rm -f

SRCS		=	ft_printf.c \
				fts_len.c \
				fts_put_nums.c \
				fts_put_strs.c \
				fts_txt.c

SRCS_BONUS	=	
# 				ft_lstadd_front.c \
# 				ft_lstclear.c \
# 				ft_lstdelone.c\
# 				ft_lstiter.c \
# 				ft_lstlast.c \
# 				ft_lstmap.c \
# 				ft_lstnew.c \
# 				ft_lstsize.c

OBJS		=	${SRCS:.c=.o}
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

# RULES DECLARATION:
all:			${NAME}

${NAME}:		${OBJS}
					ar -rc ${NAME} ${OBJS}
					ranlib ${NAME}

clean:
				${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
					${RM} ${NAME}

bonus:			${OBJS} ${OBJS_BONUS}
					ar rc ${NAME} ${OBJS_BONUS}
					ranlib ${NAME}
 
re:				fclean all

.PHONY:			all clean fclean re bonus