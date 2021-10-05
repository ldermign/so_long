/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:46:40 by ldermign          #+#    #+#             */
/*   Updated: 2021/10/05 14:18:42 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode)
{
	if (keycode == 65307)
		quit(s()->map, "You pressed the escape button. Goodbye !\n", 3, 0);
	if (keycode == 97 || keycode == 115 || keycode == 100 || keycode == 119)
	{
		if (keycode == 97
			&& s()->map->map[s()->map->plr_y][(s()->map->plr_x - 1)] != '1')
			move(s()->img, s()->map, s()->map->plr_y, s()->map->plr_x - 1);
		if (keycode == 115
			&& s()->map->map[(s()->map->plr_y + 1)][(s()->map->plr_x)] != '1')
			move(s()->img, s()->map, s()->map->plr_y + 1, s()->map->plr_x);
		if (keycode == 100
			&& s()->map->map[s()->map->plr_y][(s()->map->plr_x + 1)] != '1')
			move(s()->img, s()->map, s()->map->plr_y, s()->map->plr_x + 1);
		if (keycode == 119
			&& s()->map->map[(s()->map->plr_y - 1)][(s()->map->plr_x)] != '1')
			move(s()->img, s()->map, s()->map->plr_y - 1, s()->map->plr_x);
		mlx_put_image_to_window(s()->img->mlx, s()->img->win,
			s()->img->img, 0, 0);
	}
	return (SUCCESS);
}

int	close_cross(void)
{
	quit(s()->map, "You clicked on the cross. Goodbye !\n", 3, 0);
	return (0);
}

int	redraw(void)
{
	mlx_put_image_to_window(s()->img->mlx, s()->img->win, s()->img->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	all_check(ac, av, s()->map);
	ft_init_img(s()->map, s()->img);
	s()->img->mlx = mlx_init();
	s()->img->win = mlx_new_window(s()->img->mlx, s()->img->width,
		s()->img->height, "So_long");
	s()->img->img = mlx_new_image(s()->img->mlx, s()->img->width,
		s()->img->height);
	s()->img->addr = mlx_get_data_addr(s()->img->img, &s()->img->bpp,
		&s()->img->size_line, &s()->img->endian);
	get_map_xpm(s()->img, s()->map);
	mlx_hook(s()->img->win, 2, 1L << 0, &key_press, (void *)0);
	mlx_hook(s()->img->win, 17, 1L << 0, &close_cross, (void *)0);
	mlx_hook(s()->img->win, 12, 1L << 15, &redraw, (void *)0);
	mlx_loop(s()->img->mlx);
	exit (0);
}
