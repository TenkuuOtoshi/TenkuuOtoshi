/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:14:14 by tlarraze          #+#    #+#             */
/*   Updated: 2022/06/24 17:22:28 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//g ft_so_long.c ft_map.c ft_utils.c ft_img.c -L. -lft -I. -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

s_ptr	ft_start(s_ptr ptr, char *map)
{
	int		size;

	size = 48;
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, ft_window_size(map, 'h'), ft_window_size(map, 'v'), "Test mlx 42 Reborn !");
	ft_load_img(&ptr, size);
	ptr.map = ft_make_tab(ptr.map, map);
	ft_make_map(&ptr);
	return (ptr);
}

int	ft_window_size(char *map, int side)
{
	int		pixel;
	int		fd;
	char	*str;

	pixel = 0;
	fd = open(map, O_RDONLY);
	if (side == 'h')
	{
		str = get_next_line(fd);
		pixel = ft_strlen(str);
		free(str);
		return (pixel * 48 - 48);
	}
	if (side == 'v')
	{
		str = get_next_line(fd);
		while (str != NULL)
		{
			free(str);
			pixel++;
			str = get_next_line(fd);
		}
	}
	free(str);
	close(fd);
	return (pixel * 48);
}

int	use_key(int key, s_ptr *ptr)
{
	if (key == XK_Escape)
	{
		ft_free(ptr);
		exit(0);
	}
	if (key == XK_w || key == XK_Up)
	{
		if (ft_move(ptr, ptr->ph, ptr->pv - 48, 'w') == 1)
			ft_last_move(ptr, ptr->ph, ptr->pv + 48);
	}
	if (key == XK_a || key == XK_Left)
	{
		if (ft_move(ptr, ptr->ph - 48, ptr->pv, 'a') == 1)
			ft_last_move(ptr, ptr->ph + 48, ptr->pv);
	}
	if (key == XK_d || key == XK_Right)
	{
		if (ft_move(ptr, ptr->ph + 48, ptr->pv, 'd') == 1)
			ft_last_move(ptr, ptr->ph - 48, ptr->pv);
	}
	if (key == XK_s|| key == XK_Down)
	{
		if (ft_move(ptr, ptr->ph, ptr->pv + 48, 's') == 1)
			ft_last_move(ptr, ptr->ph, ptr->pv - 48);
	}
	if (ptr->ph == ptr->eh && ptr->pv == ptr->ev && ptr->end == 1)
	{
		ft_free(ptr);
		exit(0);
	}
	return (0);
}

int	ft_close(s_ptr *ptr)
{
	ft_free(ptr);
	exit(0);
	(void)ptr;
}

int	main(int argc, char **argv)
{
	s_ptr	ptr;

	if (!argv[1])
	{
		ft_putstr("A map name is needed =)");
		return (0);
	}
	ptr.end = 0;
	ptr.end_allow = 0;
	ptr = ft_start(ptr, argv[1]);
	//mlx_loop_hook(ptr.mlx_ptr, ft_next_frame, ptr.player);
	mlx_hook(ptr.win_ptr, 2, 1L<<0, use_key, &ptr);
	mlx_hook(ptr.win_ptr, 17, 1L<<2, ft_close, &ptr);
	mlx_loop(ptr.mlx_ptr);
	return (0);
	(void)argc;
}
