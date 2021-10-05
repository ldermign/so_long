#include "so_long.h"

t_s	*s(void)
{
	static t_s	*stc = NULL;

	if (!stc)
	{
		stc = calloc(1, sizeof(t_s));
		if (!stc)
			return (NULL);
		stc->map = calloc(1, sizeof(t_map));
		if (!stc->map)
			return (NULL);
		stc->img = calloc(1, sizeof(t_mlx));
		if (!stc->img)
			return (NULL);
	}
	return (stc);
}

void	ft_init_img(t_map *map, t_mlx *img)
{
	img->width = map->size_line * 32;
	img->height = map->len_map * 32;
	map->back = 1;
	map->front = 1;
	map->left = 1;
	map->right = 1;
	map->mvmts = 0;
}
