/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:46:27 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/10 15:06:35 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel_on_img(t_mlx *img, int x, int y, int color)
{
	int		len;
	t_color	*clr;

	// printf("img->height = %d\n", img->height);
	len = img->height;
	clr = malloc(sizeof(t_color));
	if (clr == NULL)
		quit(s()->map, "Something's wrong with malloc.\n", 0, 0);
	clr->t = get_t(color);
	clr->r = get_r(color);
	clr->g = get_g(color);
	clr->b = get_b(color);
	img->addr[(x * 4) + (len * 4 * y)] = clr->b;
	img->addr[(x * 4) + (len * 4 * y) + 1] = clr->g;
	img->addr[(x * 4) + (len * 4 * y) + 2] = clr->r;
	img->addr[(x * 4) + (len * 4 * y) + 3] = clr->t;
	// printf("%d\n", (x * 4) + (len * 4 * y) + 3);
}
