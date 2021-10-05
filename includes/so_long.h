/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:14:37 by ldermign          #+#    #+#             */
/*   Updated: 2021/10/05 11:20:14 by user42           ###   ########.fr       */
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
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "structures.h"
# define ERROR -1
# define SUCCESS 1
# define FLOOR "./textures/floor.xpm"
# define WALL "./textures/wall.xpm"
# define SH00 "./textures/sh00.xpm"
# define SH01 "./textures/sh01.xpm"
# define C00 "./textures/c00.xpm"
# define C01 "./textures/c01.xpm"
# define C02 "./textures/c02.xpm"
# define C03 "./textures/c03.xpm"
# define C04 "./textures/c04.xpm"
# define C05 "./textures/c05.xpm"
# define C06 "./textures/c06.xpm"
# define C07 "./textures/c07.xpm"
# define C08 "./textures/c08.xpm"
# define C09 "./textures/c09.xpm"
# define C10 "./textures/c10.xpm"
# define C11 "./textures/c11.xpm"
# define C12 "./textures/c12.xpm"
# define C13 "./textures/c13.xpm"
# define PLR_B1 "./textures/plr_back_1.xpm"
# define PLR_B2 "./textures/plr_back_2.xpm"
# define PLR_F1 "./textures/plr_front_1.xpm"
# define PLR_F2 "./textures/plr_front_2.xpm"
# define PLR_L1 "./textures/plr_left_1.xpm"
# define PLR_L2 "./textures/plr_left_2.xpm"
# define PLR_R1 "./textures/plr_right_1.xpm"
# define PLR_R2 "./textures/plr_right_2.xpm"
# define EXIT "./textures/exit.xpm"

/*
**	CHECK
*/

int		all_check(int ac, char **av, t_map *map);
int		check_map(t_map *map);

/*
**	INIT
*/

void	ft_init_img(t_map *map, t_mlx *img);
t_s		*s(void);

/*
**  DRAW
*/

void	get_map_xpm(t_mlx *img, t_map *map);
int		**create_txt(char *path_to_text);
void	draw_one_texture(t_mlx *img, int **color_txt, int x, int y);
void	put_texture_on_square(t_mlx *img, t_map *map, char *path_txt);
void	get_floor_wall_ex_plr(t_mlx *img, char **map, int **color_txt, char c);

/*
**	MOVEMENTS
*/

void	move(t_mlx *img, t_map *map, int next_x, int next_y);

/*
**	UTILS CHECK
*/

int		max_line(char **map);
int		ft_is_either(char c);
int		how_many_player_exit_collec(char **map, char c);
int		size_tab_char(char **tab);
int		ft_strchr_tab_wrong_cara(char **tab);

/*
**	UTILS COLOR
*/

int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

/*
**	FREE
*/

int		quit(t_map *map, char *str_err, int i, int place);
void	free_tab_int(int **tab);
void	quit_properly_image(t_mlx *img);

#endif
