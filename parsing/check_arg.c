/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:55:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/12 12:49:17 by ldermign         ###   ########.fr       */
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
		map->map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	map->map[i] = ft_strdup(line);
	free(line);
	map->map[++i] = NULL;
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
	map->len_map++;
	free(line);
	close(fd_map);
	return (SUCCESS);
}

int	ft_check_name_map(char *arg)
{
	char	*name_map;
	int		len;

	name_map = arg;
	len = ft_strlen(name_map);
	if (name_map[len - 1] != 'r' || name_map[len - 2] != 'e'
		|| name_map[len - 3] != 'b' || name_map[len - 4] != '.')
	{
		printf("Error\nWrong map\'s name.\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_check_arg(int ac, char **ag)
{
	if (ac == 1)
	{
		printf("Error\nIt's missing the map.\n");
		exit (ERROR);
	}
	else if (ac == 2)
	{
		if (ft_check_name_map(ag[1]) == -1)
			return (ERROR);
	}
	else
	{
		printf("Error\nToo many arguments.\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int	all_check(int ac, char **av, t_map *map)
{
	if (map == NULL || ft_check_arg(ac, av) == -1)
		return (ERROR);
	map->len_map = 0;
	if (check_file_descriptor(map, av[1]) == -1)
	{
		printf("Error\nCheck map's name or extension.\n");
		return (ERROR);
	}
	if (recup_map(map, av[1]) == -1)
	{
		printf("Error\nBad malloc...\n");
		return (ERROR);
	}
	if (check_map(map) == -1)
		return (ERROR);
	return (SUCCESS);
}
