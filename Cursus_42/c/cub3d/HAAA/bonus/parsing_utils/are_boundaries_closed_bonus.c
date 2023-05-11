#include "cub3D_bonus.h"

static int	check_right_cell(const char **matrix, int row, int column,
	int size_x)
{
	if (column == size_x - 1 || is_char_in_set(matrix[row][column + 1],
		ALLOWED_MAP_CHARSET) != 0)
	{
		ft_putstr_fd(2, BRED"Error\n"RESET"Map must be"
			" closed/surrounded by walls\n");
		return (1);
	}
	return (0);
}

static int	check_left_cell(const char **matrix, int row, int column)
{
	if (column == 0 || is_char_in_set(matrix[row][column - 1],
		ALLOWED_MAP_CHARSET) != 0)
	{
		ft_putstr_fd(2, BRED"Error\n"RESET"Map must be"
			" closed/surrounded by walls\n");
		return (1);
	}
	return (0);
}

static int	check_bottom_cell(const char **matrix, int row, int column,
	int size_y)
{
	if (row == size_y - 1 || is_char_in_set(matrix[row + 1][column],
		ALLOWED_MAP_CHARSET) != 0)
	{
		ft_putstr_fd(2, BRED"Error\n"RESET"Map must be"
			" closed/surrounded by walls\n");
		return (1);
	}
	return (0);
}

static int	check_top_cell(const char **matrix, int row, int column)
{
	if (row == 0 || is_char_in_set(matrix[row - 1][column],
		ALLOWED_MAP_CHARSET) != 0)
	{
		ft_putstr_fd(2, BRED"Error\n"RESET"Map must be"
			" closed/surrounded by walls\n");
		return (1);
	}
	return (0);
}

int	are_boundaries_closed(const char **matrix, int size_y, int size_x)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (j < size_x)
		{
			if (is_char_in_set(matrix[i][j], "0NSEW") == 0
				&& (check_top_cell(matrix, i, j) != 0
				|| check_bottom_cell(matrix, i, j, size_y) != 0
				|| check_left_cell(matrix, i, j) != 0
				|| check_right_cell(matrix, i, j, size_x) != 0))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
