# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 14:16:35 by ldermign          #+#    #+#              #
#    Updated: 2021/09/09 14:59:08 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	./so_long.c \
			./parsing/check_arg.c \
			./parsing/check_map.c \
			./parsing/utils_little.c \
			./parsing/utils_little_2.c \
			./draw/get_map.c \
			./draw/get_map_2.c \
			./utils/clean_quit.c \
			./utils/utils_get_colors.c \
			./utils/utils_draw.c \
			./supprimer.c

INCS	=	-I ./includes/ -I ./libft/includes/ -I ./mlx/

OBJS	=	${SRCS:.c=.o}

CC		=	clang

MLX		=	libmlx.dylib

CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

RM		=	rm -rf

all:		${NAME}

${NAME}:	${OBJS}
			${MAKE} -C libft ${INCS}
			${CC} ${CFLAGS} ${INCS} -I ${MLX} -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@ ./libft/libft.a

.c.o:
			${MAKE} -C MLX
			cp mlx/${MLX} .
			${CC} ${CFLAGS} ${INCS} -c $< -o $@

clean:
			${MAKE} -C libft clean
			${MAKE} -C mlx clean
			${RM} ${OBJS}

fclean:		clean
			${MAKE} -C libft fclean
			${RM} ${MLX}
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re