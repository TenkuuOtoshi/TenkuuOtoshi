#include "cub3D_bonus.h"

int	get_matrix_coord_colour(t_game_cub *game, int pixel_x, int pixel_y)
{
	int		y;
	int		x;
	char	coord;
	int		minimap_y;
	int		minimap_x;
	int		len_line;
	int		offset_y;
	int		offset_x;

	minimap_y = pixel_y / game->minimap_ratio_y;
	minimap_x = pixel_x / game->minimap_ratio_x;

	offset_y = minimap_y - MINMAP_ZOOM;
	offset_x = minimap_x - MINMAP_ZOOM;
	y = (int)game->player->pos_y + offset_y;//int ou round
	x = (int)game->player->pos_x + offset_x;
	if (y < 0 || y > game->map->size_y - 1)
		return (MINMAP_VOID_COLOUR);
	len_line = ft_strlen(game->map->matrix[y]);
	if (x < 0 || x > len_line)
		return (MINMAP_VOID_COLOUR);
	else if (y == 0 || y == game->map->size_y - 1 || x == 0 || x == len_line)
		return (MINMAP_WALL_COLOUR);
	coord = game->map->matrix[y][x];
	if (coord == '1')
		return (MINMAP_WALL_COLOUR);
	return (MINMAP_GROUND_COLOUR);
}

/*	if (y < (int)game->player->pos_y)
		y = -y;
	if (x < (int)game->player->pos_x)
		x = -x;
	y += (int)game->player->pos_y;
	x += (int)game->player->pos_x;*/
/*	y = pixel_y / game->matrix_ratio_y;
	x = pixel_x / game->matrix_ratio_x;*/
/*	if (pixel_x < MINMAP_W / 2)
		x = -x;
	if (pixel_y < MINMAP_H / 2)
		y = -y;*/
//	if (y > game->map->size_y -1 || x > game->map->size_x - 1
//		|| y < 0 || x < 0)
//		return (MINMAP_VOID_COLOUR);
/*	coord = game->map->matrix[(int)game->player->pos_y + y][(int)game->player->pos_x + x];
	(void)coord;
	if (is_char_in_set(coord, "NSEW") == 0)
		return (PINK);
	else if (coord == '1')
		return (MINMAP_WALL_COLOUR);
	return (MINMAP_GROUND_COLOUR);*/
