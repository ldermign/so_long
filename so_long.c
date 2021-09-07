/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:46:40 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/07 15:33:30 by ldermign         ###   ########.fr       */
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
	// printf("w = %d, h = %d\n", img->width, img->height);
	img->width = map->size_line * 32;
	img->height = map->len_map * 32;
}

void	get_floor(t_mlx *img, t_map *map, void *floor)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = 0;
	j = 0;
	width = 0;
	height = 0;
	floor = mlx_xpm_file_to_image(img->mlx, FLOOR, &width, &height);
	write(1, "ICI\n", 4);
	printf("%d\n", (int)ft_strlen(map->map[i]));
	// printf("%d\n", ft_strlen());
	while (map->map[i])
	{
		j = 0;
		// if (i == ())
		while (map->map[i][j])
		{
			// printf("w = %d, h = %d\n", width, height);
			// printf("i = [%d], j * 32 = %d, i * 32 = %d\n",i,  j * 32, i * 32);
			mlx_put_image_to_window(img->mlx, img->win, floor, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	get_wall(t_mlx *img, t_map *map, void *wall)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = 0;
	width = 0;
	height = 0;
	wall = mlx_xpm_file_to_image(img->mlx, WALL, &width, &height);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(img->mlx, img->win, wall, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	get_map_xpm(t_mlx *img)
{
	int		x;
	int		y;
	int		*color;
	t_text	*text;

	y = 0;
	color = 0;
	text = ft_calloc(1, sizeof(t_mlx));
	text->mlx = mlx_init();
	text->img = mlx_xpm_file_to_image(text->mlx, FLOOR, &text->width, &text->height);
	if (text->img == NULL)
		quit(s()->map, "Something's wrong with the floor...\n", 0, 0);
	text->text = (int *)mlx_get_data_addr(text->img, &text->bpp, &text->line, &text->endian);
	while (y <= img->height)
	{
		x = 0;
		text->x = 0;
		while (x <= img->width)
		{
			// color = (int *)mlx_get_data_addr(text->img, &text->bpp, &text->size_line, &text->endian);
			// mlx_pixel_put(img->mlx, img->win, x, y, *color);
			if (text->x == 32)
				text->x = 0;
			color = &(text->text[y * 32 + x]);
			mlx_pixel_put(img->mlx, img->win, x, y, *color);
			printf("text->x = %d, x = %d\n", text->x, x);
			text->x++;
			x++;
		}
		text->y++;
		y++;
	}
	//mlx destroy img
}

// count_h * WIN_WIDTH + count_w

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
