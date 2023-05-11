#include "cub3D_bonus.h"

t_img_cub	*init_minimap_border(char *path, t_mlx_cub *mlx)
{
	t_img_cub	*minimap_border;

	minimap_border = malloc(sizeof(t_img_cub));
	if (minimap_border == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	minimap_border->img = mlx_xpm_file_to_image(mlx->mlx_ptr, path,
			&minimap_border->width, &minimap_border->height);
	if (minimap_border->img == NULL)
	{
		free(minimap_border);
		return (NULL);
	}
	minimap_border->addr = mlx_get_data_addr(minimap_border->img,
		&(minimap_border->bpp), &(minimap_border->line_length),
		&(minimap_border->endian));
	return (minimap_border);
}
