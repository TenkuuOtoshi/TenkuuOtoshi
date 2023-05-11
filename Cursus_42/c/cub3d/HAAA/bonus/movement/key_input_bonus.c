/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:25:32 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/13 19:06:10 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	use_key_2(int key, t_game_cub *game);
static void	use_key_3(int key, t_game_cub *game);
static void	use_key_4(int key, t_game_cub *game);

int	use_key(int key, t_game_cub *game)
{
	if (key == XK_Escape)
	{
		// mlx_destroy_image(game->mlx->mlx_ptr, game->img->img);
		// mlx_destroy_window(game->mlx_game, game->win_game);
		// mlx_destroy_display(game->mlx_game);
		free_game(game);
		exit(0);
	}
	if ((key == XK_w || key == XK_Up))
	{
		printf("  %f  %f  ", game->math->p_x, game->math->p_y);
	
		if (ft_check_move_up_x(game, game->math) == 0)
			game->math->p_x += (float)cos(game->math->angle) / MOVESPEED;
		if (ft_check_move_up_y(game, game->math) == 0)
			game->math->p_y -= (float)sin(game->math->angle) / MOVESPEED;
		ft_print_everything(game, game->math);
	}
	use_key_2(key, game);
	return (0);
}

static void	use_key_2(int key, t_game_cub *game)
{
	if ((key == XK_s || key == XK_Down)) 
	{
		if (ft_check_move_down_x(game, game->math) == 0)
			game->math->p_x -= cos(game->math->angle) / MOVESPEED;
		if (ft_check_move_down_y(game, game->math) == 0)
			game->math->p_y += sin(game->math->angle) / MOVESPEED;
		ft_print_everything(game, game->math);
	}
	if (key == XK_a)
	{
		if (ft_check_move_left_x(game, game->math) == 0)
			game->math->p_x -= sin(game->math->angle) / MOVESPEED;
		if (ft_check_move_left_y(game, game->math) == 0)
			game->math->p_y -= cos(game->math->angle) / MOVESPEED;
		ft_print_everything(game, game->math);
	}
	use_key_3(key, game);
}

static void	use_key_3(int key, t_game_cub *game)
{
		if (key == XK_d)
	{
		if (ft_check_move_right_x(game, game->math) == 0)
			game->math->p_x += sin(game->math->angle) / MOVESPEED;
		if (ft_check_move_right_y(game, game->math) == 0)
		game->math->p_y += cos(game->math->angle) / MOVESPEED;
		ft_print_everything(game, game->math);
	}
	if (key == XK_Left)
	{
		game->math->angle = game->math->angle + (M_PI * ROTSPEED) / 180;
		game->math->planeX = sin(game->math->angle) * PLANE;
		game->math->planeY = cos(game->math->angle) * PLANE;
		ft_print_everything(game, game->math);
	}
	use_key_4(key, game);
}

static void	use_key_4(int key, t_game_cub *game)
{

	if (key == XK_Right)
	{
		game->math->angle = game->math->angle + (-M_PI * ROTSPEED) / 180;
		game->math->planeX = sin(game->math->angle) * PLANE;
		game->math->planeY = cos(game->math->angle) * PLANE;
		ft_print_everything(game, game->math);
	}
}
