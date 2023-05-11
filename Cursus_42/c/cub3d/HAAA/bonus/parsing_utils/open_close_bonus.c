#include "cub3D_bonus.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	close_file(int file_fd, const char *file_path)
{
	int	ret;

	ret = close(file_fd);
	if (ret < 0)
	{
		if (file_path != NULL)
			ft_printf_fd(2, BRED"Error\n"RESET"Failed to close '%s'\n",
				file_path);
	}
	return (ret);
}

int	open_o_rdonly(const char *file_path)
{
	int	file_fd;

	file_fd = open(file_path, O_RDONLY);
	if (file_fd < 0)
	{
		if (file_path != NULL)
			ft_printf_fd(2, BRED"Error\n"RESET"Failed to open '%s'\n",
				file_path);
	}
	return (file_fd);
}
