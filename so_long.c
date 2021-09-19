/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:46:40 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/16 10:17:29 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_s	*s(void)
{
	static t_s	*stc = NULL;

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

int	key_press(int keycode)
{
	if (keycode == 65307)
	{
		quit(s()->map, "You pressed the escape button. Goodbye !\n", 4, 0);
		close_window();
		mlx_destroy_display(s()->img->mlx);
		free(s()->img->mlx);
		exit (0);
	}
	if (keycode == 97 || keycode == 115 || keycode == 100 || keycode == 119)
	{
		if (keycode == 97
			&& s()->map->map[s()->map->plr_y][(s()->map->plr_x - 1)] != '1')
			move_left(s()->img, s()->map);
		if (keycode == 115
			&& s()->map->map[(s()->map->plr_y + 1)][(s()->map->plr_x)] != '1')
			move_down(s()->img, s()->map);
		if (keycode == 100
			&& s()->map->map[s()->map->plr_y][(s()->map->plr_x + 1)] != '1')
			move_right(s()->img, s()->map);
		if (keycode == 119
			&& s()->map->map[(s()->map->plr_y - 1)][(s()->map->plr_x)] != '1')
			move_up(s()->img, s()->map);
		mlx_put_image_to_window(s()->img->mlx, s()->img->win,
			s()->img->img, 0, 0);
	}
	return (SUCCESS);
}

int	close_cross(void)
{
	quit(s()->map, "You clicked on the cross. Goodbye !\n", 4, 0);
	close_window();
	mlx_destroy_display(s()->img->mlx);
	free(s()->img->mlx);
	exit (0);
}

void	ft_init_img(t_map *map, t_mlx *img)
{
	img->width = map->size_line * 32;
	img->height = map->len_map * 32;
	map->back = 1;
	map->front = 1;
	map->left = 1;
	map->right = 1;
	map->mvmts = 0;
}

int	main(int ac, char **av)
{
	if (all_check(ac, av, s()->map) == -1)
		exit (0);
	ft_init_img(s()->map, s()->img);
	s()->img->mlx = mlx_init();
	s()->img->win = mlx_new_window(s()->img->mlx, s()->img->width,
		s()->img->height, "So_long");
	s()->img->img = mlx_new_image(s()->img->mlx, s()->img->width,
		s()->img->height);
	s()->img->addr = mlx_get_data_addr(s()->img->img, &s()->img->bpp,
		&s()->img->size_line, &s()->img->endian);
	s()->img->text = (int *)mlx_get_data_addr(s()->img->img, &s()->img->bpp,
		&s()->img->size_line, &s()->img->endian);
	afficher_map(s()->map);
	get_map_xpm(s()->img, s()->map);
	mlx_hook(s()->img->win, 2, 1L << 0, &key_press, (void *)0);
	mlx_hook(s()->img->win, 17, 1L << 0, &close_cross, (void *)0);
	mlx_loop(s()->img->mlx);
	mlx_destroy_display(s()->img->mlx);
	free(s()->img->mlx);
	exit (0);
}
