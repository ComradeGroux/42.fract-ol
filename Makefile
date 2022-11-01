# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:49:40 by vgroux            #+#    #+#              #
#    Updated: 2022/11/01 19:34:18 by vgroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =     fractol

CC =         gcc
CFLAGS =     -Wall -Wextra -Werror -O3
RM =         rm -f

DIR_H = headers/
DIR_S =	srcs/
DIR_O =	objs/

SRCS_LIST =	test.c
SRCS =		${addprefix ${DIR_S}, ${SRCS_LIST}}

OBJS =		${SRCS:${DIR_S}/%.c=${DIR_O}/%.o}

DIR_LIBFT = libft/
LIBFT_INC = -I ${DIR_LIBFT}
LIBFT =	${DIR_LIBFT}libft.a

DIR_MLX = mlx/
MLX_INC = -I ${DIR_MLX}
MLX =	${DIR_MLX}libmlx.a

${NAME}: ${LIBFT} ${MLX}
	@echo "Compilation de ${NAME}"
	${CC} ${OBJS} -o ${NAME}

${LIBFT}:
	@echo "Compilation de libft..."
	@${MAKE} -sC ${@D}

${MLX}:
	@echo "Compilation de MiniLibX..."
	@${MAKE} -sC ${@D}

all: ${NAME}

${DIR_O}%.o:${DIR_S}%.c
	${CC} ${CFLAGS} ${MLX_INC} ${LIBFT_INC} -I ${DIR_H} -o $@ -c $<

clean:
	${RM} ${OBJS}
	@${MAKE} -sC mlx clean
	@${MAKE} -sC libft fclean

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re