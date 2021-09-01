/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:15:04 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/01 16:23:25 by ldermign         ###   ########.fr       */
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
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			width;		// largeur
	int			height;		// hauteur
	int			multp;
}	t_mlx;

typedef struct s_text
{
	char	*floor;
	char	*wall;
	char	*coll;
	char	*exit;
	char	*plr_N;
	char	*plr_S;
	char	*plr_E;
	char	*plr_W;
}	t_text;


typedef struct  s_structure {
	t_map	*map;
	t_mlx	*img;
	t_text	*txt;
}				t_s;

t_s	*s(void);

#endif