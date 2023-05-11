#include "cub3D_bonus.h"

t_player_cub	*init_player(void)
{
	t_player_cub	*player;

	player = malloc(sizeof(t_player_cub));
	if (player == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	player->pos_y = 0;
	player->pos_x = 0;
	return (player);
}
