/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:53:31 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/09 15:02:01 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    create_texture(t_mlx *txt, char *path_to_text)
{
	txt = ft_calloc(1, sizeof(t_mlx));

	if (txt == NULL)
		quit(s()->map, "Something's wrong with malloc.\n", 0, 0);
	txt->mlx = mlx_init();
	txt->img = mlx_xpm_file_to_image(txt->mlx, FLOOR, &txt->width, &txt->height);
	txt->text = (int *)mlx_get_data_addr(txt->img, &txt->bpp, &txt->size_line, &txt->endian);
	txt->addr = mlx_get_data_addr(txt->img, &txt->bpp, &txt->size_line, &txt->endian);
}