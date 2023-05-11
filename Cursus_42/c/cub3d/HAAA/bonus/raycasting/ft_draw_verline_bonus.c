/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_verline_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:57:09 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/13 19:05:15 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_draw_verline(int x, t_math_cub *math, t_game_cub *game)
{
	int	i;
    int color_c;
    int color_f;

	i = 0;
    color_c = convert_rgb_into_int(game->textures->text_ceiling);
    color_f = convert_rgb_into_int(game->textures->text_floor);
	//printf("  %d  %d  ", math->draw_start, math->draw_end);
	// if (math->side == 1)
	// 	color = color / 2;
	while (i < math->draw_start)
	{
		if (math->draw_start < WIN_H)
			my_mlx_pixel_put(game->mlx->screen, x, i, color_c);
		i++;
	}
	while (math->draw_start <= math->draw_end)
	{
		if (math->draw_start > 0 && math->draw_start < WIN_H && x < WIN_W && x >= 0 )
			my_mlx_pixel_put(game->mlx->screen, x, math->draw_start, 0);
		math->draw_start++;
	}
	while (math->draw_end < WIN_H && math->draw_end > 0)
	{
		my_mlx_pixel_put(game->mlx->screen, x, math->draw_end, color_f);
		math->draw_end++;
	}
	math->draw_end = 0;
	math->draw_start = 0;
}

