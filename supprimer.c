/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supprimer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:22:34 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/11 17:09:30 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	afficher_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		ft_printf("--> [ %s ]\n", map->map[i]);
		i++;
	}
}

void	afficher_couleurs(int **tab)
{
	int	ret;
	int i;
	int	j;

	ret = 0;
	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			ft_printf("tab[%d][%d] = %d.\n", i, j, tab[i][j]);
			j++;
			ret++;
		}
		i++;
	}
	ft_printf("Il y a %d pixels de couleurs, soit 32*32 = %d\n", ret, 32 * 32);
}