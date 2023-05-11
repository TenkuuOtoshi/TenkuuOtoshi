/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_move_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:50:49 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/13 18:43:07 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_check_move_left_y(t_game_cub *game, t_math_cub *math)
{
	int	x;
	int	y;

	x = math->p_x;
	if (math->p_y < 0 || math->p_y > 1019)
		return (1);
	y = math->p_y - cos(math->angle) / ( MOVESPEED / 2);
	if (game->map->matrix[x][y] != '0')
		return (1);
	return (0);
}

int	ft_check_move_right_x(t_game_cub *game, t_math_cub *math)
{
	int	x;
	int	y;

	y = math->p_y;
	if (math->p_y > 1920)
		return (1);
	x = math->p_x + sin(math->angle) / ( MOVESPEED / 2);
	if (game->map->matrix[x][y] != '0')
		return (1);
	return (0);
}

int	ft_check_move_right_y(t_game_cub *game, t_math_cub *math)
{
	int	x;
	int	y;

	x = math->p_x;
	if (math->p_y > 1920)
		return (1);
	y = math->p_y + cos(math->angle) / ( MOVESPEED / 2);
	if (game->map->matrix[x][y] != '0')
		return (1);
	return (0);
}