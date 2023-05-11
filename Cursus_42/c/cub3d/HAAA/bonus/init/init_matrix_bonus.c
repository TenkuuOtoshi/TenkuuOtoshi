#include "cub3D_bonus.h"

char	**init_matrix(int size_y, int size_x)
{
	char	**matrix;
	int		i;

	i = 0;
	matrix = malloc(sizeof(char *) * (size_y + 1));
	if (matrix == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	while (i < size_y)
	{
		matrix[i] = malloc(sizeof(char) * (size_x + 1));
		if (matrix[i] == NULL)
		{
			perror(NULL);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}
