# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:49:40 by vgroux            #+#    #+#              #
#    Updated: 2022/10/31 18:57:53 by vgroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =     fractol

CC =         gcc
CFLAGS =     -Wall -Wextra -Werror
RM =         rm -f

DIR_H = headers
DIR_I = includes
DIR_S =	srcs
DIR_O =	obj


OBJS =		${SRCS:.c=.o}


LIBFT =	includes/libft
MLX =	includes/mlx

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${NAME} ${OBJS}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re