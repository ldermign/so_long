/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:14:37 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/17 15:45:27 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <libc.h>

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
# define ERROR 0
# define SUCCESS 1

typedef struct s_map
{
	char	**map;
	int		len_map;
	int		size_line;
	int		ret;
}	t_map;

/*
**	CHECK
*/

int		ft_check_arg(int ac, char **ag);
int		chek_file_descriptor(t_map *map, char *av);
int		recup_map(t_map *map, char *av);
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
int		how_many_player(char **map);
int		size_tab_char(char **tab);
int		ft_strchr_tab_wrong_cara(char **tab);

#endif