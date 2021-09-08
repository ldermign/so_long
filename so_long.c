/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:46:40 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/08 16:09:57 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

t_s	*s(void)
{
	static t_s *stc = NULL;

	if (!stc)
	{
		stc = calloc(1, sizeof(t_s));
		if (!stc)
			return (NULL);
		stc->map = calloc(1, sizeof(t_map));
		if (!stc->map)
			return (NULL);
		stc->img = calloc(1, sizeof(t_mlx));
		if (!stc->img)
			return (NULL);
	}
	return (stc);
}

int		key_press(int keycode)
{
	if (keycode == 53)
	{
		quit(s()->map, "You pressed the escape button. Goodbye !\n", 3, 0);
		exit (0);
	}
	return (SUCCESS);
}

int		close_cross()
{
	quit(s()->map, "You clicked on the cross. Goodbye !\n", 3, 0);
	exit (0);
	return (SUCCESS);
}

void	ft_init_img(t_map *map, t_mlx *img)
{
	// printf("w = %d, h = %d\n", img->width, img->height);
	img->width = map->size_line * 32;
	img->height = map->len_map * 32;
}

void	put_floor_on_img(t_mlx *img, int **color)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (y <= img->width)
	{
		x = 0;
		j = 0;
		while (x <= img->height)
		{
			mlx_pixel_put(img->mlx, img->win, y, x, color[i][j]);
			// my_mlx_pixel_put(img, x, y, color[i][j]);
			j++;
			if (j == 32)
				j = 0;
			x++;
		}
		i++;
		if (i == 32)
			i = 0;
		y++;
	}
}

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

void	get_map_xpm(t_mlx *img)
{
	(void)img;
	int		**color;
	t_mlx	*txt;

	txt = ft_calloc(1, sizeof(t_mlx));
	if (txt == NULL)
		quit(s()->map, "Something's wrong with malloc.\n", 0, 0);
	txt->mlx = mlx_init();
	txt->img = mlx_xpm_file_to_image(txt->mlx, FLOOR, &txt->width, &txt->height);
	txt->text = (int *)mlx_get_data_addr(txt->img, &txt->bpp, &txt->size_line, &txt->endian);
	txt->addr = mlx_get_data_addr(txt->img, &txt->bpp, &txt->size_line, &txt->endian);
	color = get_color(txt);
	put_floor_on_img(img, color);
}

int	main(int ac, char **av)
{
	all_check(ac, av, s()->map);
	ft_init_img(s()->map, s()->img);

	s()->img->mlx = mlx_init();
	s()->img->win = mlx_new_window(s()->img->mlx, s()->img->width, s()->img->height, "So_long");
	s()->img->img = mlx_new_image(s()->img->mlx, s()->img->width, s()->img->height);
	s()->img->addr = mlx_get_data_addr(s()->img->img, &s()->img->bpp, &s()->img->size_line, &s()->img->endian);

	afficher_map(s()->map);

	get_map_xpm(s()->img);

	mlx_hook(s()->img->win, 2, 1L<<0, &key_press, (void *)0);
	mlx_hook(s()->img->win, 17, 1L<<0, &close_cross, (void *)0);

	mlx_loop(s()->img->mlx);

	return (SUCCESS);
}
