/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:06:57 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/04 09:53:43 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_start_end_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[0][j])
	{
		if (map->map[0][j] != '1')
			return (1);
		j++;
	}
	while (map->map[i])
		i++;
	j = 0;
	i--;
	while (map->map[i][j])
	{
		if (map->map[i][j] != '1')
			return (i + 1);
		j++;
	}
	return (-1);
}

int	check_space(t_map *map, char **tab, int c)
{
	int	i;
	int	j;
	int	ret;

	i = 1;
	while (tab[i])
	{
		if (ft_int_strchr(tab[i], c))
		{
			j = ft_pos_strchr(tab[i], c) + ret;
			while (j < map->len_map - 1)
			{
				if (tab[i][j] == c && ((i != 0 && tab[i - 1][j] == ' ')
					|| (j != 0 && tab[i][j - 1] == ' ') || tab[i][j + 1] == ' '
					|| tab[i + 1][j] == ' '))
					return (ERROR);
			}
			ret = j;
		}
		i++;
		if (i == size_tab_char(tab) - 1)
			break ;
	}
	return (SUCCESS);
}

int	check_around(t_map *map)
{
	int	i;

	i = 0;
	map->size_line = max_line(map->map);
	while (map->map[i])
	{
		if (map->size_line != (int)ft_strlen(map->map[i]))
			return (quit(map, "This is not a rectangle...\n", 0, 0));
		if (map->map[i][0] != '1' || map->map[i][map->size_line - 1] != '1')
			return (quit(map, "It's missing a wall line ", 2, i + 1));
		i++;
	}
	return (SUCCESS);
}

int	check_map(t_map *map)
{
	if (size_tab_char(map->map) <= 2)
		return (quit(map, "Map too small.n", 0, 0));
	if (how_many_player_exit_collec(map->map, 'P') != 1)
		return (quit(map, "Not right number for player.\n", 0, 0));
	if (check_start_end_map(map) != -1)
		return (quit(map, "Check line ", 2, check_start_end_map(map)));
	if (ft_strchr_tab_wrong_cara(map->map) != -1)
		return (quit(map, "Something's wrong line ", 2,
				ft_strchr_tab_wrong_cara(map->map)));
	if (!check_around(map))
		return (ERROR);
	if (!check_space(map, map->map, '0') || !check_space(map, map->map, 'C')
		|| !check_space(map, map->map, 'E')
		|| !check_space(map, map->map, 'P'))
		return (quit(map, "It's missing some wall. Go check that.\n", 0, 0));
	if (how_many_player_exit_collec(map->map, 'C') < 2)
		return (quit(map, "Not enough collectible.\n", 0, 0));
	if (how_many_player_exit_collec(map->map, 'E') < 1)
		return (quit(map, "Where is your exit ?\n", 0, 0));
	return (SUCCESS);
}
