#include "cub3D_bonus.h"

int	get_index_element(const char **splitted, t_keys_cub keys,
	const char *file_line)
{
	int	index;

	index = 0;
	while (index < NB_TEXTURES && ft_strcmp(splitted[0], keys.keys[index]))
		index++;
	if (index == NB_TEXTURES)
		ft_printf_fd(2, BRED"Error\n"RESET"Incorrect information on line:\n%s\n",
			file_line);
	return (index);
}
