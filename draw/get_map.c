/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:40:30 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/13 14:57:24 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_one_texture(t_mlx *img, int x, int y, int **color)
{
	int ret;
	int	i;
	int	j;

	i = 0;
	ret = x;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			put_pixel_on_img(img, x, y, color[i][j]);
			x++;
			j++;
		}
		x = ret;
		y++;
		i++;
	}
}

void	get_floor(t_mlx *img, int **color)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		j = 0;
		while (x < img->width)
		{
			put_pixel_on_img(img, x, y, color[i][j]);
			x++;
			j++;
			if (j == 32)
				j = 0;

		}
		y++;
		i++;
		if (i == 32)
			i = 0;
	}
}

void	get_wall(t_mlx *img, char **map, int **color_txt)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_one_texture(img, color_txt, x, y);
			x++;
		}
		y++;
	}
}

void	get_collectibles(t_mlx *img, t_mlx *txt, char **map)
{
	(void)img;
	(void)txt;
	(void)map;
	// printf("[%ld]\n", ft_random(25));
}

void	get_map_xpm(t_mlx *img, t_map *map)
{
	int		**color;
	t_mlx	*txt;

	txt = ft_calloc(1, sizeof(t_mlx));
	if (txt == NULL)
		quit(s()->map, "Something's wrong with malloc.\n", 0, 0);
    color = create_texture(txt, FLOOR);
	get_floor(img, color);
	free_tab_int(color);
    color = create_texture(txt, WALL);
    get_wall(img, map->map, color);
	get_collectibles(img, txt, map->map);
	// free_tab_int(color);
    // color = create_texture(txt, WALL);
    // get_wall(img, map->map, color);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}
