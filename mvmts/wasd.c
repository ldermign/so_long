/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:41:41 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/15 15:48:47 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_mlx *img, t_map *map)
{
	if (map->map[map->plr_y][(map->plr_x - 1)] != '1')
	{
		if (map->map[map->plr_y][(map->plr_x - 1)] == 'E' && map->cltb == 0)
			quit(s()->map, "Congrats ! You've made it !\n", 3, 0);
		if (map->map[map->plr_y][(map->plr_x - 1)] == 'C')
		{
			map->cltb -= 1;
			map->map[map->plr_y][(map->plr_x - 1)] = '0';
		}
		if (map->map[map->plr_y][map->plr_x] == 'E')
			put_texture_on_square(img, map, EXIT);
		else
			put_texture_on_square(img, map, FLOOR);
		map->plr_x -= 1;
		if (map->left == 1)
		{
			put_texture_on_square(img, map, PLR_L2);
			map->left = 0;
		}
		else
		{
			put_texture_on_square(img, map, PLR_L1);
			map->left = 1;
		}
	}
}

void	move_down(t_mlx *img, t_map *map)
{
	if (map->map[(map->plr_y + 1)][(map->plr_x)] != '1')
	{
		if (map->map[(map->plr_y + 1)][(map->plr_x)] == 'E' && map->cltb == 0)
			quit(s()->map, "Congrats ! You've made it !\n", 3, 0);
		if (map->map[(map->plr_y + 1)][(map->plr_x)] == 'C')
		{
			map->cltb -= 1;
			map->map[(map->plr_y + 1)][(map->plr_x)] = '0';
		}
		if (map->map[map->plr_y][map->plr_x] == 'E')
			put_texture_on_square(img, map, EXIT);
		else
			put_texture_on_square(img, map, FLOOR);
		map->plr_y += 1;
		if (map->front == 1)
		{
			put_texture_on_square(img, map, PLR_F2);
			map->front = 0;
		}
		else
		{
			put_texture_on_square(img, map, PLR_F1);
			map->front = 1;
		}
	}
}

void	move_right(t_mlx *img, t_map *map)
{
	if (map->map[map->plr_y][(map->plr_x + 1)] != '1')
	{
		if (map->map[map->plr_y][(map->plr_x + 1)] == 'E' && map->cltb == 0)
			quit(s()->map, "Congrats ! You've made it !\n", 3, 0);
		if (map->map[map->plr_y][(map->plr_x + 1)] == 'C')
		{
			map->cltb -= 1;
			map->map[map->plr_y][(map->plr_x + 1)] = '0';
		}
		if (map->map[map->plr_y][map->plr_x] == 'E')
			put_texture_on_square(img, map, EXIT);
		else
			put_texture_on_square(img, map, FLOOR);
		map->plr_x += 1;
		if (map->right == 1)
		{
			put_texture_on_square(img, map, PLR_R2);
			map->right = 0;
		}
		else
		{
			put_texture_on_square(img, map, PLR_R1);
			map->right = 1;
		}
	}
}

void	move_up(t_mlx *img, t_map *map)
{
	if (map->map[(map->plr_y - 1)][(map->plr_x)] != '1')
	{
		if (map->map[(map->plr_y - 1)][(map->plr_x)] == 'E' && map->cltb == 0)
			quit(s()->map, "Congrats ! You've made it !\n", 3, 0);
		if (map->map[(map->plr_y - 1)][(map->plr_x)] == 'C')
		{
			map->cltb -= 1;
			map->map[(map->plr_y - 1)][(map->plr_x)] = '0';
		}
		if (map->map[map->plr_y][map->plr_x] == 'E')
			put_texture_on_square(img, map, EXIT);
		else
			put_texture_on_square(img, map, FLOOR);
		map->plr_y -= 1;
		if (map->back == 1)
		{
			put_texture_on_square(img, map, PLR_B2);
			map->back = 0;
		}
		else
		{
			put_texture_on_square(img, map, PLR_B1);
			map->back = 1;
		}
	}
}
