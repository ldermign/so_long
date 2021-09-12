/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:46:27 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/12 12:25:55 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel_on_img(t_mlx *img, int x, int y, int color)
{
	int		len;
	t_color	*clr;

	// printf("img->height = %d\n", img->height);
	len = img->width;
	clr = malloc(sizeof(t_color));
	if (clr == NULL)
		quit(s()->map, "Something's wrong with malloc.\n", 0, 0);
	clr->t = get_t(color);
	clr->r = get_r(color);
	clr->g = get_g(color);
	clr->b = get_b(color);
	// printf("x = %d\n", x);
	// if (y < 8 && x >= 544)
		// printf("y = %d, [%d] [%d] [%d] [%d]\n", y, (x * 4) + (len * 4 * y), (x * 4) + (len * 4 * y) +1, (x * 4) + (len * 4 * y) + 2, (x * 4) + (len * 4 * y) + 3);
	
	// img->addr[(x * 4) + (len * 4 * y)] = clr->b;
	// img->addr[(x * 4) + (len * 4 * y) + 1] = clr->g;
	// img->addr[(x * 4) + (len * 4 * y) + 2] = clr->r;
	// img->addr[(x * 4) + (len * 4 * y) + 3] = clr->t;


	// img->addr[(y * img->size_line + x * (img->bpp / 8))] = clr->t | (clr->b << 1) | (clr->g << 2) | (clr->r << 3);

	// IS GOOOD:
	img->addr[(y * img->size_line + x * (img->bpp / 8))] = clr->b;
	img->addr[(y * img->size_line + x * (img->bpp / 8)) + 1] = clr->g;
	img->addr[(y * img->size_line + x * (img->bpp / 8)) + 2] = clr->r;
	img->addr[(y * img->size_line + x * (img->bpp / 8)) + 3] = clr->t;
	// end IS GOOD

	// IS GOOD
	// *(char *)(img->addr + (y * img->size_line + x * (img->bpp / 8))) = clr->b;
	// *(char *)(img->addr + (y * img->size_line + x * (img->bpp / 8)) + 1) = clr->g;
	// *(char *)(img->addr + (y * img->size_line + x * (img->bpp / 8)) + 2) = clr->r;
	// *(char *)(img->addr + (y * img->size_line + x * (img->bpp / 8)) + 3) = clr->t;
	// end IS GOOD
	free(clr);

	// printf("%d\n", (x * 4) + (len * 4 * y) + 3);
}
