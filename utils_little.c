/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_little.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:01:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/17 19:09:19 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_wall(int c)
{
	return (c == '1');
}

int	ft_is_player(int c)
{
	return (c == 'P');
}

int	ft_is_space(int c)
{
	return (c == '0');
}

int	ft_is_collectible(int c)
{
	return (c == 'C');
}

int	ft_is_exit(int c)
{
	return (c == 'E');
}
