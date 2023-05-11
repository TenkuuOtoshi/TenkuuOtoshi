#include "cub3D_bonus.h"

t_mlx_cub	*init_mlx(void)
{
	t_mlx_cub	*mlx;

	mlx = malloc(sizeof(t_mlx_cub));
	if (mlx == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_W, WIN_H, "Cub3d of the Raie-Castor !");
	if (mlx->mlx_ptr == NULL || mlx->win_ptr == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	mlx->screen = NULL;
	mlx->minimap_border = NULL;
	return (mlx);
}
