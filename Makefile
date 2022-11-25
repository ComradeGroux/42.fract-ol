# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:49:40 by vgroux            #+#    #+#              #
#    Updated: 2022/11/25 16:04:29 by vgroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GREENGREEN = \033[38;5;46m
RED = \033[0;31m
GREY = \033[38;5;240m
RESET = \033[0m

NAME =     fractol

CC =         gcc
CFLAGS =     -Wall -Wextra -Werror -O3
RM =         rm -f

DIR_H = headers/
DIR_S =	srcs/
DIR_O =	objs/

SRCS_LIST =	error.c \
			hook.c \
			julia.c \
			keyhook.c \
			main.c \
			mandelbrot.c \
			mousehook.c \
			utils.c \

SRCS =		${addprefix ${DIR_S}, ${SRCS_LIST}}

OBJS =		${SRCS:${DIR_S}%.c=${DIR_O}%.o}

# Compile la Libft
DIR_LIBFT = libft/
LIBFT_INC = -I ${DIR_LIBFT}
LIBFT =	${DIR_LIBFT}libft.a
FT_LNK = -L ${DIR_LIBFT} -l ft

# Compile la MiniLibX suivant l'OS
ifeq (${shell uname}, Linux)
	DIR_MLX = mlx_linux/
	MLX_LNK	= -L $(DIR_MLX) -lXext -lX11 -lbsd -l mlx
else
	DIR_MLX = mlx_macos/
	MLX_LNK	= -L $(DIR_MLX) -l mlx -framework OpenGL -framework AppKit
endif
MLX_INC = -I ${DIR_MLX}
MLX =	${DIR_MLX}libmlx.a

LIBS = ${FT_LNK} ${MLX_LNK}

${NAME}: ${LIBFT} ${MLX} ${OBJS}
	@echo "$(GREENGREEN) ██████╗██████╗  █████╗  ██████╗████████╗    ██████╗ ██╗$(RESET)"
	@echo "$(GREENGREEN) ██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝   ██╔═══██╗██║$(RESET)"
	@echo "$(GREENGREEN) █████╗  ██████╔╝███████║██║        ██║█████╗██║   ██║██║$(RESET)"
	@echo "$(GREENGREEN) ██╔══╝  ██╔══██╗██╔══██║██║        ██║╚════╝██║   ██║██║$(RESET)"
	@echo "$(GREENGREEN) ██║     ██║  ██║██║  ██║╚██████╗   ██║      ╚██████╔╝███████╗$(RESET)"
	@echo "$(GREENGREEN) ╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝       ╚═════╝ ╚══════╝$(RESET)"
	${CC} ${OBJS} ${LIBS} -o ${NAME}

${LIBFT}:
	@echo "[$(GREENGREEN)${NAME}$(RESET)]: Creating Libft...${GREY}"
	${MAKE} -sC ${@D}
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: Libft Objects were created\n"

${MLX}:
	@echo "[$(GREENGREEN)${NAME}$(RESET)]: Creating MiniLibX...$(GREY)"
	${MAKE} -sC ${@D}
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: MLX Objects were created\n"

all: ${NAME}

${DIR_O}%.o:${DIR_S}%.c
	${CC} ${CFLAGS} ${LIBFT_INC} ${MLX_INC} -I ${DIR_H} -o $@ -c $<

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
