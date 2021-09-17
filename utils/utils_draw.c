/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:46:27 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/12 12:32:03 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel_on_img(t_mlx *img, int x, int y, int color)
{
	t_color	*clr;

	clr = malloc(sizeof(t_color));
	if (clr == NULL)
		quit(s()->map, "Something's wrong with malloc.\n", 0, 0);
	clr->t = get_t(color);
	clr->r = get_r(color);
	clr->g = get_g(color);
	clr->b = get_b(color);
	img->addr[(y * img->size_line + x * (img->bpp / 8))] = clr->b;
	img->addr[(y * img->size_line + x * (img->bpp / 8)) + 1] = clr->g;
	img->addr[(y * img->size_line + x * (img->bpp / 8)) + 2] = clr->r;
	img->addr[(y * img->size_line + x * (img->bpp / 8)) + 3] = clr->t;
	free(clr);
}
