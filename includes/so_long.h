/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:14:37 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/07 13:26:34 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <math.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "structures.h"
# define ERROR -1
# define SUCCESS 1
# define FLOOR "./textures/floor.xpm"
# define WALL "./textures/wall.xpm"
# define COLL
# define EXIT
# define PLR_N
# define PLR_S
# define PLR_E
# define PLR_W

/*
**	CHECK
*/

int		all_check(int ac, char **av, t_map *map);
int		check_map(t_map *map);

/*
**	UTILS CHECK
*/

int		max_line(char **map);
int		ft_is_wall(int c);
int		ft_is_player(int c);
int		ft_is_space(int c);
int		ft_is_collectible(int c);
int		ft_is_exit(int c);
int		ft_is_either(char c);
int		how_many_player_exit_collec(char **map, char c);
int		size_tab_char(char **tab);
int		ft_strchr_tab_wrong_cara(char **tab);

/*
**	UTILS
*/

int		quit(t_map *map, char *str_err, int i, int place);

/*
**	SUPPRIMER
*/

#define KRED  "\x1B[0;31m" // ROUGE
#define KGRN  "\x1B[0;32m" // VERT
#define KYEL  "\x1B[0;33m" // JAUNE
#define KBLU  "\x1B[0;34m" // BLEU
#define KMAG  "\x1B[0;35m" // MAGENTA
#define KCYN  "\x1B[0;36m" // CYAN
#define KWHT  "\x1B[0;37m" // BLANC
#define KGRE  "\x1b[1;30m" // GRIS
#define CLR_COLOR "\x1b[0m" // CLEAR COLOR
void	afficher_map(t_map *map);
#include <libc.h>

#endif