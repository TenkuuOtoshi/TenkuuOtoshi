/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_move_1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:47:36 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/13 18:45:57 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_check_next_move(t_game_cub *game, t_math_cub *math , int direction)
{
	int	x;
	int	y;

	y = math->p_y;
	if (direction == 'U')
	{
		if (math->p_y - 2 < 0)
			return (1);
		x = math->p_x + cos(math->angle) / ( MOVESPEED / 2);
		y = math->p_y - sin(math->angle) / ( MOVESPEED / 2);
		if (game->map->matrix[x][y] != '0')
			return (1);
	}
	if (direction == 'D')
	{
		if (math->p_y > 1919)
			return (1);
		x = math->p_x - cos(math->angle) / ( MOVESPEED / 2);
		y = math->p_y  + sin(math->angle) / ( MOVESPEED / 2);
		if (game->map->matrix[x][y] != '0')
			return (1);
	}
	return (0);
}

int	ft_check_move_up_x(t_game_cub *game, t_math_cub *math)
{
	int	x;
	int	y;

	y = math->p_y;
	if (math->p_y < 0 || math->p_y > 1019)// or 1080 ?
		return (1);
	x = math->p_x + cos(math->angle) / ( MOVESPEED / 2);
	if (game->map->matrix[x][y] != '0')
		return (1);
	return (0);
}

int	ft_check_move_up_y(t_game_cub *game, t_math_cub *math)
{
	int	x;
	int	y;

	x = math->p_x;
	if (math->p_y < 0 || math->p_y > 1019)
		return (1);
	y = math->p_y - sin(math->angle) / ( MOVESPEED / 2);
	if (game->map->matrix[x][y] != '0')
		return (1);
	return (0);
}

int	ft_check_move_down_x(t_game_cub *game, t_math_cub *math)
{
	int	x;
	int	y;

	y = math->p_y;
	if (math->p_y < 0 || math->p_y > 1019)
		return (1);
	x = math->p_x - cos(math->angle) / ( MOVESPEED / 2);
	if (game->map->matrix[x][y] != '0')
		return (1);
	return (0);
}

int	ft_check_move_down_y(t_game_cub *game, t_math_cub *math)
{
	int	x;
	int	y;

	x = math->p_x;
	if (math->p_y < 0 || math->p_y > 1019)
		return (1);
	y = math->p_y + sin(math->angle) / ( MOVESPEED / 2);
	if (game->map->matrix[x][y] != '0')
		return (1);
	return (0);
}

int	ft_check_move_left_x(t_game_cub *game, t_math_cub *math)
{
	int	x;
	int	y;

	y = math->p_y;
	if (math->p_y < 0 || math->p_y > 1019)
		return (1);
	x = math->p_x - sin(math->angle) / ( MOVESPEED / 2);
	if (game->map->matrix[x][y] != '0')
		return (1);
	return (0);
}