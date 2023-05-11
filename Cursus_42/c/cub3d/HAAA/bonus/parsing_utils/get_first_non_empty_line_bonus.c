#include "cub3D_bonus.h"

char	*get_first_non_empty_line(int file_fd)
{
	char		*file_line;

	file_line = get_next_line(file_fd);
	if (file_line == NULL)
		return (NULL);
	while (file_line != NULL && is_line_empty(file_line) == 0)
	{
		free(file_line);
		file_line = get_next_line(file_fd);
	}
	return (file_line);
}
