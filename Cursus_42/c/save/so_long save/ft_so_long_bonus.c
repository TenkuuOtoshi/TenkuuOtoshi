/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:14:14 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/11 16:04:17 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_ptr	ft_start(t_ptr ptr, char *map)
{
	ptr.size = 48;
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, ft_window_size(map, 'h', &ptr),
			ft_window_size(map, 'v', &ptr), "So long Adventure !");
	ptr.map = ft_make_tab(ptr.map, map, &ptr);
	ft_load_img(&ptr, ptr.size);
	ft_make_map(&ptr, 0, 0);
	ptr.moves = 0;
	return (ptr);
}

int	ft_window_size(char *map, int side, t_ptr *ptr)
{
	int		pixel;
	int		fd;
	char	*str;

	pixel = 0;
	str = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error\nThis file don't exist or the file is not working\n");
		mlx_destroy_display(ptr->mlx_ptr);
		free(ptr->mlx_ptr);
		exit(0);
	}
	if (side == 'h')
	{
		str = get_next_line(fd);
		pixel = ft_so_long_strlen(str);
		free(str);
		return (pixel * 48);
	}
	return (ft_window_side_v(pixel, side, fd, str));
}

int	use_key(int key, t_ptr *ptr)
{
	if (ptr->death == 1)
		ft_free(ptr);
	if (key == XK_Escape)
		ft_free(ptr);
	if ((key == XK_w || key == XK_Up) && ptr->death == 0)
	{
		if (ft_move(ptr, ptr->ph, ptr->pv - 48, 'w') == 1)
			ft_last_move(ptr, ptr->ph, ptr->pv + 48);
	}
	if ((key == XK_a || key == XK_Left) && ptr->death == 0)
	{
		if (ft_move(ptr, ptr->ph - 48, ptr->pv, 'a') == 1)
			ft_last_move(ptr, ptr->ph + 48, ptr->pv);
	}
	ft_use_key2(key, ptr);
	return (0);
}

int	ft_close(t_ptr *ptr)
{
	ft_free(ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_ptr	ptr;

	if (!argv[1])
	{
		ft_putstr("Error\nNo map given");
		return (0);
	}
	ptr.map_name = argv[1];
	ft_init(&ptr);
	ptr = ft_start(ptr, argv[1]);
	ptr.allow_map_change = 1;
	ft_write_moves(&ptr);
	mlx_hook(ptr.win_ptr, 2, 1L << 0, use_key, &ptr);
	mlx_hook(ptr.win_ptr, 17, 1L << 2, ft_close, &ptr);
	mlx_loop_hook(ptr.mlx_ptr, ft_chest_sprite, &ptr);
	mlx_loop(ptr.mlx_ptr);
	return (0);
	(void)argc;
}
