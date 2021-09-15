/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:40:30 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/15 15:52:18 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_floor_wall_ex_plr(t_mlx *img, char **map, int **color_txt, char c)
{
	int	ret;
	int	i;
	int	j;

	ret = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				draw_one_texture(img, color_txt, j, i);
				ret++;
			}
			if (ret == 1 && (c == 'E' || c == 'P'))
				return ;
			j++;
		}
		i++;
	}
}

int	**put_one_collectible(t_mlx *txt)
{
	const t_txt_col	which_txt[] = {
		{0, SH00, create_txt}, {1, SH01, create_txt}, {2, C00, create_txt},
		{3, C01, create_txt}, {4, C02, create_txt}, {5, C03, create_txt},
		{6, C04, create_txt}, {7, C05, create_txt}, {8, C06, create_txt},
		{9, C07, create_txt}, {10, C08, create_txt}, {11, C09, create_txt},
		{12, C10, create_txt}, {13, C11, create_txt}, {14, C12, create_txt},
		{15, C13, create_txt}, {-1, NULL, NULL}
	};
	int				i;
	int				**color;
	int				ran_text;

	i = 0;
	color = NULL;
	ran_text = ft_random(15);
	while (which_txt[i].which_col != -1)
	{
		if (ran_text == which_txt[i].which_col)
		{
			color = which_txt[i].f(txt, which_txt[i].path);
			break ;
		}
		i++;
	}
	return (color);
}

void	get_collectibles(t_mlx *img, t_mlx *txt, char **map)
{
	int	i;
	int	j;
	int	**color;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				color = put_one_collectible(txt);
				draw_one_texture(img, color, j, i);
				free_tab_int(color);
			}
			j++;
		}
		i++;
	}
}

void	put_texture_on_square(t_mlx *img, t_map *map, char *path_txt)
{
	int		**color;
	t_mlx	*txt;

	txt = ft_calloc(1, sizeof(t_mlx));
	if (txt == NULL)
		quit(map, "Something's wrong with malloc.\n", 0, 0);
	color = create_txt(txt, path_txt);
	draw_one_texture(img, color, map->plr_x, map->plr_y);
	free_tab_int(color);
}

void	get_map_xpm(t_mlx *img, t_map *map)
{
	int		**color;
	t_mlx	*txt;

	txt = ft_calloc(1, sizeof(t_mlx));
	if (txt == NULL)
		quit(map, "Something's wrong with malloc.\n", 0, 0);
	color = create_txt(txt, FLOOR);
	get_floor_wall_ex_plr(img, map->map, color, '0');
	free_tab_int(color);
	color = create_txt(txt, WALL);
	get_floor_wall_ex_plr(img, map->map, color, '1');
	free_tab_int(color);
	get_collectibles(img, txt, map->map);
	color = create_txt(txt, EXIT);
	get_floor_wall_ex_plr(img, map->map, color, 'E');
	free_tab_int(color);
	color = create_txt(txt, PLR_F1);
	get_floor_wall_ex_plr(img, map->map, color, 'P');
	free_tab_int(color);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}
