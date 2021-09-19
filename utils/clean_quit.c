/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:19:17 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/16 10:17:43 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab_int(int **tab)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_print_map(char **map, int red)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (i == red)
			ft_printf("\x1b[0mLine [ %d ]\t==>\t\x1B[0;31m%s\n", i + 1, map[i]);
		else
			ft_printf("\x1b[0mLine [ %d ]\t==>\t\x1B[1;30m%s\n", i + 1, map[i]);
		i++;
	}
}

int	quit(t_map *map, char *str_err, int i, int place)
{
	if (i <= 2)
		ft_printf("Error\n");
	if (str_err != NULL)
		ft_printf("%s", str_err);
	if ((i == 1 || i == 2) && str_err != NULL)
		ft_printf("[ %d ].\n", place);
	if (i == 2)
		ft_print_map(map->map, place - 1);
	ft_free_tab(map->map);
	free(map);
	if (i == 4)
	{
		return (0);
		// free(s()->img->mlx);
		// free(s()->img->win);
		// free(s()->img->img);
		// free(s()->img);
		// if (s()->img->addr != NULL)
		// 	free(s()->img->addr);
		// if (s()->img->text != NULL)
		// 	free(s()->img->text);
	}
	free(s()->img);
	free(s());
	exit (0);
}

void	free_mlx(t_mlx *img)
{
	free(img->mlx);
	free(img->win);
	free(img->img);
	// if (img->addr != NULL)
	// 	free(img->addr);
	// if (img->text != NULL)
	// 	free(img->text);
	free(img);
}

void	close_window()
{
	mlx_destroy_window(s()->img->mlx, s()->img->win);
	s()->img->win = NULL;
}