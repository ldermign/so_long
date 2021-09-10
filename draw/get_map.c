/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:40:30 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/10 15:49:54 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	put_one_texture(t_mlx *img, int x, int y, int **color)
// {
// 	int ret;
// 	int	i;
// 	int	j;

// 	i = 0;
// 	ret = x;
// 	while (i < 32)
// 	{
// 		j = 0;
// 		while (j < 32)
// 		{
// 			put_pixel_on_img(img, x, y, color[j][i]);
// 			x++;
// 			j++;
// 		}
// 		x = ret;
// 		y++;
// 		i++;
// 	}
// }

void	get_floor(t_mlx *img, int **color)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	printf("height = %d, width = %d\n", img->height, img->width);
	while (y < img->height)
	{
		x = 0;
		j = 0;
		while (x < img->width)
		{
			printf("i = %d, j = %d, x = %d, y = %d\n", i, j, x, y);
			put_pixel_on_img(img, x, y, color[i][j]);
			j++;
			if (j == 32)
				j = 0;
			x++;
		}
		i++;
		if (i == 32)
			i = 0;
		y++;
			// printf("x = %d\n", x);
	}
	// printf("test\n");
	// i = 0;j = 0;x = 0;y = 0;
	// while (y < img->height)
	// {
	// 	x = 0;
	// 	while (x < img->width)
	// 	{
	// 		put_one_texture(img, y, x, color);
	// 		x += 32;
	// 	}
	// 	y += 32;
	// }
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	draw_wall(t_mlx *img, int **color_txt, int x, int y)
{
	int ret;
	int	i;
	int	j;

	i = 0;
	x *= 32;
	y *= 32;
	ret = y;
	while (i < 32)
	{
		y = ret;
		j = 0;
		while (j < 32)
		{
			put_pixel_on_img(img, x, y, color_txt[i][j]);
			j++;
			y++;
		}
		i++;
		x++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	get_wall(t_mlx *img, char **map, int **color_txt)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				draw_wall(img, color_txt, j, i);
			j++;
		}
		i++;
	}
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
    color = create_texture(txt, WALL);
	(void)map;
    // get_wall(img, map->map, color);
}
