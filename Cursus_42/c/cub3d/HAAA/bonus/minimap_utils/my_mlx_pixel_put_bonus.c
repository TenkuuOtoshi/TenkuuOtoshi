#include "cub3D_bonus.h"

void	my_mlx_pixel_put(t_img_cub *img	, int x, int y, int colour)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = colour;
}
