# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:49:40 by vgroux            #+#    #+#              #
#    Updated: 2022/11/02 16:43:58 by vgroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREENGREEN = \033[38;5;46m
RED = \033[0;31m
BLUE = \033[0;34m
GREY = \033[38;5;240m
RESET = \033[0m

NAME =     fractol

CC =         gcc
CFLAGS =     -Wall -Wextra -Werror -O3
RM =         rm -f

DIR_H = headers/
DIR_S =	srcs/
DIR_O =	objs/

DIR_LIBFT = libft/
LIBFT_INC = -I ${DIR_LIBFT}
LIBFT =	${DIR_LIBFT}libft.a

DIR_MLX = mlx/
MLX_INC = -I ${DIR_MLX}
MLX =	${DIR_MLX}libmlx.a

LIBS = -L ${DIR_LIBFT} -lft -L ${DIR_MLX} -lmlx -framework OpenGL -framework AppKit

SRCS_LIST =	fractol.c \
			fractol_error.c \

SRCS =		${addprefix ${DIR_S}, ${SRCS_LIST}}

OBJS =		${SRCS:${DIR_S}%.c=${DIR_O}%.o}

${NAME}: ${LIBFT} ${MLX} ${OBJS}
	@echo "$(GREENGREEN)   ██████╗██████╗  █████╗  ██████╗████████╗    ██████╗ ██╗$(RESET)"
	@echo "$(GREENGREEN)   ██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝   ██╔═══██╗██║$(RESET)"
	@echo "$(GREENGREEN)   █████╗  ██████╔╝███████║██║        ██║█████╗██║   ██║██║$(RESET)"
	@echo "$(GREENGREEN)   ██╔══╝  ██╔══██╗██╔══██║██║        ██║╚════╝██║   ██║██║$(RESET)"
	@echo "$(GREENGREEN)   ██║     ██║  ██║██║  ██║╚██████╗   ██║      ╚██████╔╝███████╗$(RESET)"
	@echo "$(GREENGREEN)   ╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝       ╚═════╝ ╚══════╝$(RESET)"
	${CC} ${LIBS} ${OBJS} -o ${NAME}

${LIBFT}:
	@echo "[$(GREENGREEN)Fract-ol$(RESET)]: Creating Libft..."
	${MAKE} -sC ${@D}
	@echo "$(RESET)[$(GREENGREEN)Fract-ol$(RESET)]: Libft Objects were created\n"
${MLX}:
	@echo "[$(GREENGREEN)Fract-ol$(RESET)]: Creating MiniLibX...$(GREY)"
	${MAKE} -sC ${@D}
	@echo "$(RESET)[$(GREENGREEN)Fract-ol$(RESET)]: MLX Objects were created\n"

all: ${NAME}

${DIR_O}%.o:${DIR_S}%.c
	${CC} ${CFLAGS} -I ${DIR_H} ${LIBFT_INC} ${MLX_INC} -o $@ -c $<

clean:
	@echo "$(RED) ██████╗██╗     ███████╗ █████╗ ███╗   ██╗██╗███╗   ██╗ ██████╗$(RESET)"
	@echo "$(RED) ██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║██║████╗  ██║██╔════╝$(RESET)"
	@echo "$(RED) ██║     ██║     █████╗  ███████║██╔██╗ ██║██║██╔██╗ ██║██║  ███╗$(RESET)"
	@echo "$(RED) ██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║██║██║╚██╗██║██║   ██║$(RESET)"
	@echo "$(RED) ╚██████╗███████╗███████╗██║  ██║██║ ╚████║██║██║ ╚████║╚██████╔╝$(RESET)"
	@echo "$(RED)  ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝ ╚═════╝ $(RESET)"
	${RM} ${OBJS}

libclean:
	@echo "Clean de MiniLibX"
	${MAKE} -sC ${DIR_MLX} clean
	@echo "Clean de libft"
	${MAKE} -sC ${DIR_LIBFT} fclean

fclean: clean libclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re