# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 14:16:35 by ldermign          #+#    #+#              #
#    Updated: 2021/09/15 15:42:37 by ldermign         ###   ########.fr        #
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
			./mvmts/wasd.c \
			./utils/clean_quit.c \
			./utils/utils_get_colors.c \
			./utils/utils_draw.c \
			./supprimer.c

INCS	=	-I ./includes/ -I ./libft/includes/ -I ./minilibx-linux/

OBJS	=	${SRCS:.c=.o}

CC		=	clang

MLX		=	libmlx_Linux.a

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

all:		${NAME}

${NAME}:	${OBJS}
			${MAKE} -C libft ${INCS}
			${CC} -o ${NAME} ${INCS} -L./minilibx-linux -lbsd -lmlx -lXext -lX11 -lm -o $(NAME) ./libft/libft.a

.c.o:
			${MAKE} -C ./minilibx-linux/
			cp ./minilibx-linux/${MLX} .
			${CC} ${CFLAGS} ${INCS} -Imlx_linux -O3 -c $< -o $@

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