/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:19:17 by ldermign          #+#    #+#             */
/*   Updated: 2021/10/05 14:19:20 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab_int(int **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
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
			printf("Line [ %d ]\t==>\t\x1B[0;31m%s\x1b[0m\n", i + 1, map[i]);
		else
			printf("Line [ %d ]\t==>\t%s\n\x1b[0m", i + 1, map[i]);
		i++;
	}
}

int	quit(t_map *map, char *str_err, int i, int place)
{
	if (i <= 2)
		printf("Error\n");
	if (str_err != NULL)
		printf("%s", str_err);
	if ((i == 1 || i == 2) && str_err != NULL)
		printf("[ %d ].\n", place);
	if (i == 2)
		ft_print_map(map->map, place - 1);
	ft_free_tab(map->map);
	free(map);
	if (i <= 2)
	{
		free(s()->img);
		free(s());
		exit (0);
	}
	quit_properly_image(s()->img);
	return (0);
}

void	quit_properly_image(t_mlx *img)
{
	if (img)
	{
		if (img->img)
			mlx_destroy_image(img->mlx, img->img);
		if (img->win)
			mlx_destroy_window(img->mlx, img->win);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
	}
	free(s()->img);
	free(s());
	exit (0);
}
