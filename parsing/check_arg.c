/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:55:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/10/05 14:19:22 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	recup_map(t_map *map, char *av)
{
	int		i;
	int		ret;
	int		fd_map;
	char	*line;

	i = 0;
	fd_map = open(av, O_RDONLY);
	line = 0;
	map->map = (char **)malloc(sizeof(char *) * (map->len_map + 1));
	if (map->map == NULL || fd_map == -1)
		return (ERROR);
	while (1)
	{
		ret = get_next_line(fd_map, &line);
		if (ret <= 0)
			break ;
		map->map[i++] = ft_strdup(line);
		free(line);
	}
	if (line[0] != '\0')
		map->map[i++] = ft_strdup(line);
	free(line);
	map->map[i] = NULL;
	close(fd_map);
	return (SUCCESS);
}

int	check_file_descriptor(t_map *map, char *av)
{
	int		ret;
	int		fd_map;
	char	*line;

	fd_map = open(av, O_RDONLY);
	line = 0;
	if (fd_map < 0)
		return (ERROR);
	while (1)
	{
		ret = get_next_line(fd_map, &line);
		if (ret == -1)
			return (ERROR);
		if (ret <= 0)
			break ;
		map->len_map++;
		free(line);
	}
	if (line[0] != '\0')
		map->len_map++;
	free(line);
	close(fd_map);
	return (SUCCESS);
}

int	ft_check_extension_map(char *arg)
{
	char	*name_map;
	int		len;

	name_map = arg;
	len = ft_strlen(name_map);
	if (name_map[len - 1] != 'r' || name_map[len - 2] != 'e'
		|| name_map[len - 3] != 'b' || name_map[len - 4] != '.')
		quit(s()->map, "Wrong map\'s name.\n", 0, 0);
	return (SUCCESS);
}

int	all_check(int ac, char **av, t_map *map)
{
	if (ac == 1)
		quit(s()->map, "It's missing the map.\n", 0, 0);
	else if (ac == 2)
		ft_check_extension_map(av[1]);
	else
		quit(s()->map, "Too many arguments.\n", 0, 0);
	map->len_map = 0;
	if (check_file_descriptor(map, av[1]) == -1)
		quit(s()->map, "Check map's name.\n", 0, 0);
	if (recup_map(map, av[1]) == -1)
		quit(s()->map, "Bad malloc in map's oppening...\n", 0, 0);
	check_map(map);
	return (SUCCESS);
}
