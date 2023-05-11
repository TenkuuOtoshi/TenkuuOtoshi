/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_math_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:16:52 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/13 19:06:56 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_init_value(t_game_cub *game)
{
	ft_init_math_value(game, game->math);
}

void	ft_init_math_value(t_game_cub *game, t_math_cub *math)
{
	math->angle = M_PI / 2;
	math->DirY = 0.0;
	math->DirX = -1.0; //NORD
	math->hit = 0;
	math->planeY = 0.90;
	math->planeX = 0.00;
	math->p_y = game->player->pos_x;
	math->p_x = game->player->pos_y;
}