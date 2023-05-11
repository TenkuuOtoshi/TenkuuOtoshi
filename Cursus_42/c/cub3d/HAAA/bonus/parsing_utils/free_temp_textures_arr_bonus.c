#include "cub3D_bonus.h"

void	free_temp_textures_arr(char **textures)
{
	int	i;

	i = 0;
	while (i < NB_TEXTURES)
	{
		if (textures[i] != NULL)
			free(textures[i]);
		i++;
	}
	free(textures);
}
