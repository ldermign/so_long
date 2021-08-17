/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:32:38 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/12 18:36:31 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
