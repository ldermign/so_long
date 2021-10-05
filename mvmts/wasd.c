/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:41:41 by ldermign          #+#    #+#             */
/*   Updated: 2021/10/05 13:40:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_texture_on_square(t_mlx *img, t_map *map, char *path_txt)
{
	int		**color;

	color = create_txt(path_txt);
	draw_one_texture(img, color, map->plr_x, map->plr_y);
	free_tab_int(color);
}

int	get_which_turn(int act_y, int act_x, int next_y, int next_x)
{
	if (act_y != next_y)
	{
		if (act_y > next_y)
			return ('B');
		else
			return ('F');
	}
	else
	{
		if (act_x > next_x)
			return ('L');
		else
			return ('R');
	}
	return ('1');
}

void	put_right_turn_for_texture2(t_mlx *img, t_map *map, char *txt)
{
	put_texture_on_square(img, map, txt);
	map->last_move = txt;
	if (map->text == 'B' && map->back == 1)
		map->back = 0;
	else if (map->text == 'B' && map->back == 0)
		map->back = 1;
	else if (map->text == 'F' && map->front == 1)
		map->front = 0;
	else if (map->text == 'F' && map->front == 0)
		map->front = 1;
	else if (map->text == 'L' && map->left == 1)
		map->left = 0;
	else if (map->text == 'L' && map->left == 0)
		map->left = 1;
	else if (map->text == 'R' && map->right == 1)
		map->right = 0;
	else if (map->text == 'R' && map->right == 0)
		map->right = 1;
	s()->map->mvmts++;
	printf("%d movements.\n", s()->map->mvmts);
}

void	put_right_turn_for_texture1(t_mlx *img, t_map *map)
{
	if (map->text == 'B' && map->back == 1)
		put_right_turn_for_texture2(img, map, PLR_B1);
	else if (map->text == 'B' && map->back == 0)
		put_right_turn_for_texture2(img, map, PLR_B2);
	else if (map->text == 'F' && map->front == 1)
		put_right_turn_for_texture2(img, map, PLR_F1);
	else if (map->text == 'F' && map->front == 0)
		put_right_turn_for_texture2(img, map, PLR_F2);
	else if (map->text == 'L' && map->left == 1)
		put_right_turn_for_texture2(img, map, PLR_L1);
	else if (map->text == 'L' && map->left == 0)
		put_right_turn_for_texture2(img, map, PLR_L2);
	else if (map->text == 'R' && map->right == 1)
		put_right_turn_for_texture2(img, map, PLR_R1);
	else if (map->text == 'R' && map->right == 0)
		put_right_turn_for_texture2(img, map, PLR_R2);
}

void	move(t_mlx *img, t_map *map, int next_y, int next_x)
{
	if (map->map[next_y][(next_x)] == 'E' && map->cltb == 0)
		quit(s()->map, "Congrats ! You've made it !\n", 3, 0);
	map->text = get_which_turn(map->plr_y, map->plr_x, next_y, next_x);
	if (map->map[next_y][(next_x)] == 'C')
	{
		map->cltb -= 1;
		map->map[next_y][(next_x)] = '0';
	}
	if (map->map[map->plr_y][map->plr_x] == 'E')
		put_texture_on_square(img, map, EXIT);
	else
		put_texture_on_square(img, map, FLOOR);
	if (map->map[next_y][next_y] != 'E')
		map->map[next_y][(next_x)] = 'P';
	map->plr_y = next_y;
	map->plr_x = next_x;
	put_right_turn_for_texture1(img, map);
}
