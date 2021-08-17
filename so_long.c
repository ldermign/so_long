/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:46:40 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/12 18:24:47 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	all_check(int ac, char **av)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL || !ft_check_arg(ac, av))
		return (ERROR);
	map->len_map = 0;
	if (!chek_file_descriptor(map, av[1]))
	{
		ft_printf("ERROR\nCheck map's name or extension.\n");
		return (ERROR);
	}
	if (!recup_map(map, av[1]))
	{
		ft_printf("Error\nBad malloc...\n");
		return (ERROR);
	}
	if (!check_map(map))
		return (ERROR);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	if (!all_check(ac, av))
		return (ERROR);
	return (0);
}
