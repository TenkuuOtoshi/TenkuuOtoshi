#include "cub3D_bonus.h"

int	main(int argc, char **argv)
{
	t_game_cub	*game;
	int			ret;

	if (argc != 2)
	{
		ft_printf_fd(2, BRED"Error\n"RESET"Correct usage is: ./cub3D"
			" <./path_to_the_file>\n");
		return (1);
	}
	ret = 0;
	game = init_game(argv[1]);
	if (game == NULL
		|| check_file_validity(game->file_path) != 0
		|| check_element_part(game) != 0
		|| check_map_part(game) != 0)
//		|| display_minimap(game) != 0)
		ret = 1;
	if (ret == 0)
		launch_program(game);
	free_game(game);
	return (ret);
}
