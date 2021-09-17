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

INCS	=	-I ./includes/ -I ./libft/includes/ -I ./mlx/

OBJS	=	${SRCS:.c=.o}

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

all:		${NAME}

${NAME}:	${OBJS}
			${MAKE} -C libft ${INCS}
			cp ./libft/libft.a .
			${CC} ${CFLAGS} -o ${NAME} ${INCS} -L ./mlx/ -lmlx -lXext -lX11 -lm ./libft/libft.a
			# ${CC} ${CFLAGS} -o ${NAME} ${INCS} ${SRCS} -L ./mlx/ -lmlx -lXext -lX11 -lm

.c.o:
			${MAKE} -C ./mlx/
			cp ./mlx/libmlx_Linux.a .
			${CC} ${CFLAGS} ${INCS} -Imlx -Ibass -c $< -o ${<:c=o}
			# ${INCS} -Imlx_linux -O3 -c $< -o $@

clean:
			${MAKE} -C libft clean
			${MAKE} -C mlx clean
			${RM} ${OBJS}

fclean:		clean
			${MAKE} -C libft fclean
			${RM} libmlx_Linux.a
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re