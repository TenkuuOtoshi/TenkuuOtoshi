/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:14:14 by tlarraze          #+#    #+#             */
/*   Updated: 2022/06/20 13:35:02 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//g ft_so_long.c ft_map.c -L. -lft -I. -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
//Matriceeeeee

s_ptr	ft_start(s_ptr ptr, char *map)
{
	int		size;
	s_chest	**chest;
	s_chest	player;

	size = 48;
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, ft_window_size(map, 'h'), ft_window_size(map, 'v'), "Test mlx 42 Reborn !");
	ft_background(ptr, ft_window_size(map, 'h'), ft_window_size(map, 'v'));
	ft_wall(map, ptr, size);
	player = ft_player(player, ptr, map, size);
	chest = malloc(ft_search('C', map) + 1 * sizeof(s_chest));
	chest = ft_spawn_chest(map, size, ptr, chest);
	player.ptr = ptr;
	mlx_hook(player.ptr.win_ptr, 2, 1L<<0, use_key, player.ptr.win_ptr);
	return (ptr);
}

int	ft_window_size(char *map, int side)
{
	int		pixel;
	int		fd;

	pixel = 0;
	fd = open(map, O_RDONLY);
	if (side == 'h')
		return (ft_strlen(get_next_line(fd)) * 48 - 48);
	if (side == 'v')
	{
		while (get_next_line(fd) != NULL)
			pixel++;
	}
	close(fd);
	return (pixel * 48);
}

int	use_key(int key, s_chest *player)
{
	int	size;

	size = 48;
	write(1, &key, 1);
	if (key == XK_Escape)
		exit(0);
	if (key == XK_Down)
	{
		//mlx_destroy_image(player->ptr.mlx_ptr, player->img_ptr);
		//mlx_put_image_to_window(player.ptr.mlx_ptr, player.ptr.win_ptr, player.img_ptr, player.h + 48, player.v + 48);
		//player->img_ptr = mlx_xpm_file_to_image(player->ptr.mlx_ptr, "P.xpm", &size, &size);
		//mlx_put_image_to_window(player->ptr.mlx_ptr, player->ptr.win_ptr, player->img_ptr, player->h + 48, player->v + 48);
		//tmp = mlx_xpm_file_to_image(player->ptr.mlx_ptr, "P.xpm", &size, &size);
		//mlx_put_image_to_window(player->ptr.mlx_ptr, player->ptr.win_ptr, tmp, 250, 250);
		player->h += 48;
		player->v += 48;
		(void)size;
	}
	return (0);
}


int	main(int argc, char **argv)
{
	s_ptr	ptr;

	if (!argv[1])
	{
		ft_putstr("A map name is needed =)");
		return (0);
	}
	ptr = ft_start(ptr, argv[1]);
	//mlx_loop_hook(ptr.mlx_ptr, ft_next_frame, ptr.player);
	mlx_loop(ptr.mlx_ptr);
	return (0);
	(void)argc;
}
