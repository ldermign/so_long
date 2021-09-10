/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:53:31 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/10 10:46:12 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	**create_texture(t_mlx *txt, char *path_to_text)
{
	int	**color;

	color = NULL;
	txt->mlx = mlx_init();
	txt->img = mlx_xpm_file_to_image(txt->mlx, path_to_text, &txt->width, &txt->height);
	txt->text = (int *)mlx_get_data_addr(txt->img, &txt->bpp, &txt->size_line, &txt->endian);
	txt->addr = mlx_get_data_addr(txt->img, &txt->bpp, &txt->size_line, &txt->endian);
	color = get_color(txt);
	return (color);
}
