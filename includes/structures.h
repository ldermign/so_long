/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:15:04 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/16 10:19:35 by ldermign         ###   ########.fr       */
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
	int		cltb;
	int		plr_y;
	int		plr_x;
	int		back;
	int		front;
	int		left;
	int		right;
	int		mvmts;
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
	int		width;
	int		height;
}	t_mlx;

typedef struct  s_structure
{
	t_map	*map;
	t_mlx	*img;
}	t_s;

typedef struct s_colors
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	t;
}	t_color;

t_s	*s(void);

typedef struct s_texture_collectible
{
	int		which_col;
	char	*path;
	int		**(*f)(char *path_to_text);
}	t_txt_col;

#endif