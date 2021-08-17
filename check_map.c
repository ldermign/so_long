/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:06:57 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/17 19:15:30 by ldermign         ###   ########.fr       */
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
			return (ERROR);
		j++;
	}
	while (map->map[i])
		i++;
	j = 0;
	i--;
	while (map->map[i][j])
	{
		if (map->map[i][j] != '1')
			return (ERROR);
		j++;
	}
	return (SUCCESS);
}

int	check_wall_around(t_map *map, char **tab, int c)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		if (ft_int_strchr(tab[i], c))
		{
			j = 0;
			while (j < map->len_map - 1)
			{
				if (tab[i][j] == c && ((i != 0 && tab[i - 1][j] == ' ')
					|| (j != 0 && tab[i][j - 1] == ' ') || tab[i][j + 1] == ' '
					|| tab[i + 1][j] == ' '))
					return (ERROR);
				j++;
			}
		}
		i++;
		if (i == size_tab_char(tab) - 1)
			break ;
	}
	return (SUCCESS);
}

int	check_wall_around(char **map, int size_line)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][size_line - 1] != '1')
		{
			ft_printf("Error\nIt's missing a wall line %d.\n", i + 1);
			return (ERROR);
		}
		if (size_line != (int)ft_strlen(map[i]))
		{
			ft_printf("Error\nThis is not a rectangle...\n");
			return (ERROR);
		}
		i++;
	}
}

int	check_map(t_map *map)
{
	int	i;

	i = 0;
	map->size_line = max_line(map->map);
	if (how_many_player(map->map) != 1)
	{
		ft_printf("Error\nNot right number of player.\n");
		return (ERROR);
	}
	if (!check_start_end_map(map))
	{
		ft_printf("Error\nCheck first or last line.\n");
		return (ERROR);
	}
	if (!ft_strchr_tab_wrong_cara(map->map))
	{
		ft_printf("Something's wrong in the map.\n");
		return (ERROR);
	}
	if (!check_wall_around(map->map, map->size_line))
		return (ERROR);
	if (!check_wall_around(map, map->map, '0')
		|| !check_wall_around(map, map->map, 'C')
		|| !check_wall_around(map, map->map, 'E')
		|| !check_wall_around(map, map->map, 'P'))
	{
		printf("Error\nIt's missing some wall. Go check that.\n");
		return (ERROR);
	}
	return (SUCCESS);
}
