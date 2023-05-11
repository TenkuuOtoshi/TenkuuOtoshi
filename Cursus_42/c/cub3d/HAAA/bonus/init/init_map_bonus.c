#include "cub3D_bonus.h"

t_map_cub	*init_map(void)
{
	t_map_cub	*map;

	map = malloc(sizeof(t_map_cub));
	if (map == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	map->matrix = NULL;
	map->size_y = 0;
	map->size_x = 0;
	return (map);
}
