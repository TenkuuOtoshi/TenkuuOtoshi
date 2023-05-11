#include "cub3D_bonus.h"

int	is_there_forbidden_char(const char *str, const char *allowed_charset)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_char_in_set(str[i], allowed_charset) != 0)
			return (0);
		i++;
	}
	return (1);
}
