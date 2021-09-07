/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:15:04 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/07 15:20:44 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

#include "so_long.h"

typedef struct s_map
{
	char	**map;
	int		len_map;
	int		size_line;
	int		ret;
}	t_map;

typedef struct  s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		*text;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;		// largeur
	int		height;		// hauteur
}	t_mlx;

typedef struct	s_texture
{
	void	*mlx;
	void	*img;
	int		*text;
	int		bpp;
	int		line;
	int		endian;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_text;

typedef struct  s_structure {
	t_map	*map;
	t_mlx	*img;
}				t_s;

t_s	*s(void);

#endif