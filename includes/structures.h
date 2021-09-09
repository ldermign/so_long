/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:15:04 by ldermign          #+#    #+#             */
/*   Updated: 2021/09/09 14:38:18 by ldermign         ###   ########.fr       */
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
	void	*img;		/* pointer qui permet d'identifier l'image */
	char	*addr;		/* string contenant tous les pixels de l'image */
	int		*text;
	int		bpp;		/* nombre de bits par pixels -> 32 */
	int		size_line;	/* taille de la addr */
	int		endian;		/* permet de signifier la fin d'une image*/
	int		width;		// largeur
	int		height;		// hauteur
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

#endif