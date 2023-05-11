#include "cub3D_bonus.h"

static int	set_starting_pos(t_game_cub *game, int row, int column)
{
	if (game->player->pos_y != 0 || game->player->pos_x != 0)
	{
		ft_putstr_fd(2, BRED"Error\n"RESET"Map can only contain one"
			" starting point for the player\n");
		return (1);
	}
	game->player->pos_y = row;
	game->player->pos_x = column;
	return (0);
}

int	get_player_pos(t_game_cub *game, const char **matrix)
{
	int	i;
	int	j;

	i = 0;
	game->player = init_player();
	if (game->player == NULL)
		return (1);
	while (matrix[i] != NULL)
	{
		j = 0;
		while (j < game->map->size_x)
		{
			if (is_char_in_set(matrix[i][j], "NSWE") == 0
				&& set_starting_pos(game, i, j) != 0)
				return (1);
			j++;
		}
		i++;
	}
	if (game->player->pos_y == 0 || game->player->pos_x == 0)
	{
		ft_printf_fd(2, BRED"Error\n"RESET"The map must contain one starting"
			" point for the player\n");
		return (1);
	}
	return (0);
}
