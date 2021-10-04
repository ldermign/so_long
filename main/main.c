/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:46:40 by ldermign          #+#    #+#             */
/*   Updated: 2021/10/04 16:06:57 by user42           ###   ########.fr       */
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
		stc->text = calloc(1, sizeof(t_list));
		if (!stc->text)
			return (NULL);
	}
	return (stc);
}

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

void	redraw_collectibles(t_mlx *img, t_map *map, t_list *text, int **color)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'C')
			{
				color = create_txt(text->content);
				draw_one_texture(img, color, x, y);
				free_tab_int(color);
				text = text->next;
			}
			x++;
		}
		y++;
	}
}

int	redraw(void)
{
	int		**color;

	color = create_txt(FLOOR);
	get_floor_wall_ex_plr(s()->img, s()->map->map, color, '0');
	free_tab_int(color);
	color = create_txt(WALL);
	get_floor_wall_ex_plr(s()->img, s()->map->map, color, '1');
	free_tab_int(color);
	color = create_txt(EXIT);
	get_floor_wall_ex_plr(s()->img, s()->map->map, color, 'E');
	free_tab_int(color);
	color = create_txt(s()->map->last_move);
	get_floor_wall_ex_plr(s()->img, s()->map->map, color, 'P');
	free_tab_int(color);
	// PLUS QUE CA
	//redraw_collectibles(s()->img, s()->map, s()->text, color);
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
