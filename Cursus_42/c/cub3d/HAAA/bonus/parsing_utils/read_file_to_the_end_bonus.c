#include "cub3D_bonus.h"

void	read_file_to_the_end(int file_fd, char *file_line)
{
	free(file_line);
	file_line = get_next_line(file_fd);
	while (file_line != NULL)
	{
		free(file_line);
		file_line = get_next_line(file_fd);
	}
}
