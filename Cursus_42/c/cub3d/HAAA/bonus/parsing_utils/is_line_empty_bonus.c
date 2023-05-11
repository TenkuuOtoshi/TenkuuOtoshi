#include "cub3D_bonus.h"

int	is_line_empty(const char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '\n')
		return (0);
	while (ft_isspace(str[i]) == 1)
		i++;
	if (i != ft_strlen(str))
		return (1);
	return (0);
}
