/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_input_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:37:33 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/13 17:53:18 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_move_cursor(t_game_cub *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_mouse_get_pos(game->mlx->mlx_ptr, game->mlx->win_ptr, &x, &y);
	if (x > game->mouse_x)
	{
		game->math->angle = game->math->angle + (-M_PI * ROTSPEED) / 180;
		game->math->planeX = sin(game->math->angle) * PLANE;
		game->math->planeY = cos(game->math->angle) * PLANE;
		mlx_mouse_move(game->mlx->mlx_ptr, game->mlx->win_ptr, WIN_H / 2, WIN_W / 2);
		mlx_mouse_get_pos(game->mlx->mlx_ptr, game->mlx->win_ptr, &game->mouse_x, &game->mouse_y);
		ft_print_everything(game, game->math);
	}
	else if (x < game->mouse_x)	
	{
		game->math->angle = game->math->angle + (M_PI * ROTSPEED) / 180;
		game->math->planeX = sin(game->math->angle) * PLANE;
		game->math->planeY = cos(game->math->angle) * PLANE;
		mlx_mouse_move(game->mlx->mlx_ptr, game->mlx->win_ptr, WIN_H / 2, WIN_W / 2);
		mlx_mouse_get_pos(game->mlx->mlx_ptr, game->mlx->win_ptr, &game->mouse_x, &game->mouse_y);
		ft_print_everything(game, game->math);
	}
	return (0);
}

void	ft_print_everything(t_game_cub *game, t_math_cub *math)
{
	ft_raycasting(game, math);
	display_minimap(game);
	//ft_put_mini_map(game);
	//ft_put_mini_map_cursor(game);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr, game->mlx->screen->img, 0, 0);
}
