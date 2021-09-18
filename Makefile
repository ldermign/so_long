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

INCS	=	./includes/

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

OBJS	=	${SRCS:.c=.o}

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -g3 -I ${INCS}

MLFLGS	=	-L./mlx -lbsd -lmlx -lXext -lX11 -lm

all:		${NAME}

${NAME}:	${OBJS} ${INCS}
			${MAKE} -C ./libft
			${MAKE} -C ./mlx
			${CC} -o ${NAME} ${OBJS} ${CFLAGS} ${MLFLGS} libft/libft.a

.c.o:		${CC} ${CFLAGS} -c $< -o ${<:c=o}

clean:
			${MAKE} -C libft clean
			${MAKE} -C mlx clean
			rm -f ${OBJS}

fclean:		clean
			${MAKE} -C libft fclean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re