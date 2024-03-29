/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_little_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:46:52 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/15 11:49:55 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_either(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

int	how_many_player_exit_collec(char **map, char c)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				tmp++;
			j++;
		}
		i++;
	}
	if (c == 'C' && tmp >= 1)
		s()->map->cltb = tmp;
	return (tmp);
}

int	size_tab_char(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

int	ft_strchr_tab_wrong_cara(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_is_either(tab[i][j]))
				return (i + 1);
			j++;
		}
		i++;
	}
	return (-1);
}

int	max_line(char **map)
{
	int	i;
	int	tmp;
	int	size;

	i = 0;
	size = 0;
	while (map[i])
	{
		tmp = ft_strlen(map[i]);
		if (tmp > size)
			size = tmp;
		i++;
	}
	return (size);
}
