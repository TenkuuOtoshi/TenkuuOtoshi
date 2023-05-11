#include "cub3D_bonus.h"

int	get_pixel(t_img_cub *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	return (*(int*)dst);
}
