#include "cub3D_bonus.h"

int	fill_matrix_holes(char **matrix, int size_x)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (j < size_x)
		{
			if (ft_isspace(matrix[i][j]) == 1 || matrix[i][j] == '\0')
				matrix[i][j] = '1';
			j++;
		}
		matrix[i][j] = '\0';
		i++;
	}
	return (0);
}
