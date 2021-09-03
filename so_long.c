/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:46:40 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/03 15:28:47 by ldermign         ###   ########.fr       */
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
	printf("w = %d, h = %d\n", img->width, img->height);
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
		// return ;
		i++;
	}
}

void	get_map_xpm(t_map *map, t_mlx *img)
{
	void	*text;

	text = NULL;
	get_floor(img, map, text);
	get_wall(img, map, text);
}

void	utils(t_map *map, t_mlx *img)
{
	afficher_map(map);
	printf("img->width = %d --> %d\nimg->height = %d --> %d\n", img->width / 32, img->width, img->height / 32, img->height);
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



/// Faire un x64 ?????