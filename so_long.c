/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:46:40 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/01 16:34:40 by ldermign         ###   ########.fr       */
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
		stc->txt = calloc(1, sizeof(t_text));
		if (!stc->txt)
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



void	get_textures(t_text *txt, int multp)
{
	const t_recup textures[] = {
		{}
	}
	if (multp == 64)
	{
		txt->floor = ft_strdup("./textures/floor_600.xpm");
		txt->wall = ft_strdup("./textures/wall_64.xpm");
		txt->coll = ft_strdup("./textures/coll_64.xpm");
		txt->exit = ft_strdup("./textures/exit_64.xpm");
		txt->plr_N = ft_strdup("./textures/plr_N_64.xpm");
		txt->plr_S = ft_strdup("./textures/plr_S_64.xpm");
		txt->plr_E = ft_strdup("./textures/plr_E_64.xpm");
		txt->plr_W = ft_strdup("./textures/plr_W_64.xpm");
	}
	else if (multp == 32)
	{
		txt->floor = ft_strdup("./textures/floor_600.xpm");
		txt->wall = ft_strdup("./textures/wall_32.xpm");
		txt->coll = ft_strdup("./textures/coll_32.xpm");
		txt->exit = ft_strdup("./textures/exit_32.xpm");
		txt->plr_N = ft_strdup("./textures/plr_N_32.xpm");
		txt->plr_S = ft_strdup("./textures/plr_S_32.xpm");
		txt->plr_E = ft_strdup("./textures/plr_E_32.xpm");
		txt->plr_W = ft_strdup("./textures/plr_W_32.xpm");
	}
	else if (multp == 16)
	{
		txt->floor = ft_strdup("./textures/floor_600.xpm");
		txt->wall = ft_strdup("./textures/wall_16.xpm");
		txt->coll = ft_strdup("./textures/wall_16.xpm");
		txt->exit = ft_strdup("./textures/exit_16.xpm");
		txt->plr_N = ft_strdup("./textures/plr_N_16.xpm");
		txt->plr_S = ft_strdup("./textures/plr_S_16.xpm");
		txt->plr_E = ft_strdup("./textures/plr_E_16.xpm");
		txt->plr_W = ft_strdup("./textures/plr_W_16.xpm");
	}
	else if (multp == 8)
	{
		txt->floor = ft_strdup("./textures/floor_8.xpm");
		txt->wall = ft_strdup("./textures/wall_8.xpm");
		txt->coll = ft_strdup("./textures/coll_8.xpm");
		txt->exit = ft_strdup("./textures/exit_8.xpm");
		txt->plr_N = ft_strdup("./textures/plr_N_8.xpm");
		txt->plr_S = ft_strdup("./textures/plr_S_8.xpm");
		txt->plr_E = ft_strdup("./textures/plr_E_8.xpm");
		txt->plr_W = ft_strdup("./textures/plr_W_8.xpm");
	}
}

void	get_map_xpm(t_map *map, t_mlx *img, t_text *txt)
{
	int	i = 0, j = 0;
	void	*wall;
	int		width;
	int		height;

	width = 0;
	height = 0;
	get_textures(txt, img->multp);
	wall = mlx_xpm_file_to_image(img->mlx, txt->floor, &width, &height);
	mlx_put_image_to_window(img->mlx, img->win, wall, 0, 0);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
			{
				wall = mlx_xpm_file_to_image(img->mlx, txt->wall, &width, &height);
				mlx_put_image_to_window(img->mlx, img->win, wall, j * img->multp, i * img->multp);
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

	get_map_xpm(s()->map, s()->img, s()->txt);

	mlx_hook(s()->img->win, 2, 1L<<0, &key_press, (void *)0);
	mlx_hook(s()->img->win, 17, 1L<<0, &close_cross, (void *)0);

	mlx_loop(s()->img->mlx);

	return (SUCCESS);
}



/// Faire un x64 ?????