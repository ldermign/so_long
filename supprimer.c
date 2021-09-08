/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supprimer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:22:34 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/08 10:42:55 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	afficher_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		printf("--> [ %s ]\n", map->map[i]);
		i++;
	}
}

void	afficher_couleurs(int **tab)
{
	int i;
	int	j;

	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			printf("tab[%d][%d] = %d.\n", i, j, tab[i][j]);
			j++;
		}
		i++;
	}
}