#include "cub3D_bonus.h"

t_game_cub	*init_game(const char *file_path)
{
	t_game_cub	*game;

	game = malloc(sizeof(t_game_cub));
	if (game == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	game->math = malloc(sizeof(t_math_cub));
	if (game->math == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	game->map = NULL;
	game->player = NULL;
	game->mlx = NULL;
	game->file_path = file_path;
	game->matrix_ratio_y = 0;
	game->matrix_ratio_x = 0;
	game->minimap_ratio_y = (float)MINMAP_H / (MINMAP_ZOOM * 2 + 1);
	game->minimap_ratio_x = (float)MINMAP_W / (MINMAP_ZOOM * 2 + 1);
	return (game);
}
