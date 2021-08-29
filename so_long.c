/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:46:40 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/29 23:02:42 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int	max_w;
	int	max_h;

	img->width = map->size_line * 32;
	img->height = map->len_map * 32;
	img->multp = 32;
	mlx_get_screen_size(img->mlx, &max_w, &max_h);
	if (img->width > max_w || img->height > max_h)
	{
		img->width = map->size_line * 16;
		img->height = map->len_map * 16;
		img->multp = 16;
	}
	if (img->width > max_w || img->height > max_h)
	{
		img->width = map->size_line * 8;
		img->height = map->len_map * 8;
		img->multp = 8;
	}
	if (img->width > max_w || img->height > max_h)
	{
		img->width = map->size_line;
		img->height = map->len_map;
		img->multp = 1;
	}
	// ajouter fonction qui check si map plus grande que le max
	// addapter en fonction
}

void	get_map_xpm(t_map *map, t_mlx *img)
{
	int	i = 0, j = 0;
	void	*wall;
	int		ret;
	int		width;
	int		height;

	ret = 0;
	width = 0;
	height = 0;
	while (map->map[i])
	{
		j = 0;
		ret = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
			{
				wall = mlx_xpm_file_to_image(img->mlx, WALL, &width, &height);
				img->addr = mlx_get_data_addr(s()->img->img, &s()->img->bpp, &s()->img->size_line, &s()->img->endian);
				mlx_put_image_to_window(img->mlx, img->win, wall, i * 32, ret);
			}
			j++;
		}
		i++;
	}
}

void	utils(t_map *map, t_mlx *img)
{
	afficher_map(map);
	printf("Multiplicateur = %d\n", img->multp);
	printf("img->width = %d --> %d\nimg->height = %d --> %d\n", img->width / img->multp, img->width, img->height / img->multp, img->height);
}

int	main(int ac, char **av)
{
	if (!all_check(ac, av, s()->map))
		return (ERROR);
	ft_init_img(s()->map, s()->img);

	s()->img->mlx = mlx_init();
	s()->img->win = mlx_new_window(s()->img->mlx, s()->img->width, s()->img->height, "So_long");
	s()->img->img = mlx_new_image(s()->img->mlx, s()->img->width, s()->img->height);
	s()->img->addr = mlx_get_data_addr(s()->img->img, &s()->img->bpp, &s()->img->size_line, &s()->img->endian);

	utils(s()->map, s()->img);

	get_map_xpm(s()->map, s()->img);

	mlx_hook(s()->img->win, 2, 1L<<0, &key_press, (void *)0);
	mlx_hook(s()->img->win, 17, 1L<<0, &close_cross, (void *)0);

	mlx_loop(s()->img->mlx);

	return (SUCCESS);
}

