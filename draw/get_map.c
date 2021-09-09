/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:40:30 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/09 15:01:24 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**get_color(t_mlx *txt)
{
	int	i;
	int	j;
	int	**tab;

	i = 0;
	txt->size_line /= 4;
	tab = malloc(sizeof(int *) * 32);
	if (tab == NULL)
		quit(s()->map, "Something's wrong with malloc.\n", 0, 0);
	while (i < 32)
	{
		j = 0;
		tab[i] = malloc(sizeof(int) * 32);
		if (tab[i] == NULL)
			quit(s()->map, "Something's wrong with malloc.\n", 0, 0);
		while (j < 32)
		{
			tab[i][j] = txt->text[j * txt->size_line + i];
			j++;
		}
		i++;
	}
	return (tab);
}

void	get_floor(t_mlx *img, t_mlx *txt, int **color)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 0;
	color = get_color(txt);
	while (x < img->width)
	{
		y = 0;
		j = 0;
		while (y < img->height)
		{
			put_pixel_on_img(img, x, y, color[i][j]);
			j++;
			if (j == 32)
				j = 0;
			y++;
		}
		i++;
		if (i == 32)
			i = 0;
		x++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	get_map_xpm(t_mlx *img)
{
	int		**color;
	t_mlx	*txt;

	color = NULL;
    txt = NULL;
    create_texture(txt, FLOOR);
	get_floor(img, txt, color);
    create_texture(txt, FLOOR)
    get_wall(img, txt, color);
}
