#include "cub3D_bonus.h"

static void	free_mlx(t_mlx_cub *mlx)
{
//	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	if (mlx->mlx_ptr != NULL)
	{
		free(mlx->mlx_ptr);
		mlx->mlx_ptr = NULL;
	}
	free(mlx);
	mlx = NULL;
}

static void	free_text_walls(t_frame_cub **text_walls, t_mlx_cub *mlx)
{
	int	i;

	i = 0;
	while (text_walls[i] != NULL)
	{
		if (text_walls[i]->img != NULL)
			mlx_destroy_image(mlx->mlx_ptr, text_walls[i]->img);
		if (text_walls[i]->path != NULL)
			free(text_walls[i]->path);
		free(text_walls[i]);
		i++;
	}
	free(text_walls);
}

static void	free_textures(t_textures_cub *textures, t_mlx_cub *mlx)
{
	int	i;

	i = 0;
	if (textures->text_walls != NULL)
	{
		free_text_walls(textures->text_walls, mlx);
		textures->text_walls = NULL;
	}
	free_double_arr(textures->text_floor);
	free_double_arr(textures->text_ceiling);
	free(textures);
}

static void	free_map(t_map_cub *map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map->matrix != NULL && map->matrix[i] != NULL)
	{
		free(map->matrix[i]);
		map->matrix[i] = NULL;
		i++;
	}
	if (map->matrix != NULL)
	{
		free(map->matrix);
		map->matrix = NULL;
	}
	free(map);
}

void	free_game(t_game_cub *game)
{
	if (game == NULL)
		return ;
	if (game->map != NULL)
		free_map(game->map);
	if (game->player != NULL)
		free(game->player);
	if (game->textures != NULL)
		free_textures(game->textures, game->mlx);
	if (game->mlx->minimap_border != NULL)
	{
		mlx_destroy_image(game->mlx->mlx_ptr, game->mlx->minimap_border->img);
		free(game->mlx->minimap_border);
	}
	if (game->mlx != NULL)
		free_mlx(game->mlx);
	free(game);
}
