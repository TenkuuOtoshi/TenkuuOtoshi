#include "cub3D_bonus.h"

t_textures_cub	*init_textures(void)
{
	t_textures_cub	*textures;

	textures = malloc(sizeof(t_textures_cub));
	if (textures == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	textures->text_walls = NULL;
	textures->text_floor = NULL;
	textures->text_ceiling = NULL;
	return (textures);
}
