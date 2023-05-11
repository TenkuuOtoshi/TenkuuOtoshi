#include "cub3D_bonus.h"

int	convert_rgb_into_int(char **rgb)
{
	int	colour;

	colour = 0;
	colour = (ft_atoi(rgb[0]) << 16)
		+ (ft_atoi(rgb[1]) << 8)
		+ (ft_atoi(rgb[2]));
	return (colour);
}
