/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:33:46 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/10 10:54:07 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_t(int color)
{
	return ((color & 0xFF000000) >> 24);
}

int	get_r(int color)
{
	return ((color & 0x00FF0000) >> 16);
}

int	get_g(int color)
{
	return ((color & 0x0000FF00) >> 8);
}

int	get_b(int color)
{
	return (color & 0x000000FF);
}
