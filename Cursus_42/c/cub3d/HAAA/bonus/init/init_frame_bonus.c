#include "cub3D_bonus.h"

t_frame_cub	*init_frame(char *path, t_mlx_cub *mlx)
{
	t_frame_cub	*frame;

	frame = malloc(sizeof(t_frame_cub));
	if (frame == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	frame->path = ft_strdup(path);
	if (frame->path == NULL)
		return (NULL);
	frame->img = mlx_xpm_file_to_image(mlx->mlx_ptr, frame->path,
			&frame->width, &frame->height);
	if (frame->img == NULL)
	{
		free(frame->path);
		free(frame);
		return (NULL);
	}
	frame->addr = mlx_get_data_addr(frame->img, &(frame->bpp),
			&(frame->line_length), &(frame->endian));
	return (frame);
}
