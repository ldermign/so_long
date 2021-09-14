/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:53:31 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/14 11:31:15 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_one_texture(t_mlx *img, int **color_txt, int x, int y)
{
	int ret;
	int	i;
	int	j;

	i = 0;
	x *= 32;
	y *= 32;
	ret = x;
	while (i < 32)
	{
		x = ret;
		j = 0;
		while (j < 32)
		{
			put_pixel_on_img(img, x, y, color_txt[i][j]);
			j++;
			x++;
		}
		i++;
		y++;
	}
}

int	**get_color(t_mlx *txt)
{
	int	x;
	int	y;
	int	**tab;

	y = 0;
	txt->size_line /= 4;
	tab = malloc(sizeof(int *) * 32);
	if (tab == NULL)
		quit(s()->map, "Something's wrong with malloc.\n", 0, 0);
	while (y < 32)
	{
		x = 0;
		tab[y] = malloc(sizeof(int) * 32);
		if (tab[y] == NULL)
			quit(s()->map, "Something's wrong with malloc.\n", 0, 0);
		while (x < 32)
		{
			tab[y][x] = txt->text[y * txt->size_line + x];
			x++;
		}
		y++;
	}
	txt->size_line *= 4;
	return (tab);
}

int	**create_txt(t_mlx *txt, char *path_to_text)
{
	int	**color;

	color = NULL;
	txt->mlx = mlx_init();
	txt->img = mlx_xpm_file_to_image(txt->mlx, path_to_text, &txt->width, &txt->height);
	txt->text = (int *)mlx_get_data_addr(txt->img, &txt->bpp, &txt->size_line, &txt->endian);
	txt->addr = mlx_get_data_addr(txt->img, &txt->bpp, &txt->size_line, &txt->endian);
	color = get_color(txt);
	return (color);
}
