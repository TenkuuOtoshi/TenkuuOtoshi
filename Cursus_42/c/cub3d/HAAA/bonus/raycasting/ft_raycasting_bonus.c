/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:40:13 by tlarraze          #+#    #+#             */
/*   Updated: 2023/03/13 19:03:16 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	ft_calculate_wall_height(t_math_cub *math);
static void	ft_calculate_ray_length(t_math_cub *math);
static void	ft_send_ray_to_wall(t_game_cub *game, t_math_cub *math);
static void	ft_set_math_values(t_math_cub *math, int x);

void	ft_raycasting(t_game_cub *game, t_math_cub *math)
{
	int	x;

	x = 0;
	math->DirX = cos(math->angle);
	math->DirY = -sin(math->angle);
	while (x < WIN_W)
	{
		ft_set_math_values(math, x);
		ft_calculate_ray_length(math);
		ft_send_ray_to_wall(game, math);
		ft_calculate_wall_height(math);
		//ft_draw_everything(game, math);// to do
		if (game->map->matrix[math->mapX][math->mapY] > '0')
			ft_draw_verline(x, math, game);
		x++;
	}
}

static void	ft_calculate_wall_height(t_math_cub *math)
{
	if (math->side == 0)
		math->perpWallDist = (math->sideDistX - math->deltaDistX);
	else
		math->perpWallDist = (math->sideDistY - math->deltaDistY);
	math->lineheight = (int)WIN_H / (math->perpWallDist);
	math->draw_start = (-math->lineheight / 2) + (WIN_H / 2);
	if (math->draw_start < 0)
		math->draw_start = 0;
	math->draw_end = (math->lineheight / 2) + (WIN_H / 2);
	if (math->draw_end >= WIN_H || math->draw_end < 0)
		math->draw_end = WIN_H - 1;
}

static void	ft_send_ray_to_wall(t_game_cub *game, t_math_cub *math)
{
	while (math->hit == 0)
	{
		if (math->sideDistX < math->sideDistY)
		{
			math->sideDistX += math->deltaDistX;
			math->mapX += math->stepX;
			math->side = 0;
		}
		else
		{
			math->sideDistY += math->deltaDistY;
			math->mapY += math->stepY;
			math->side = 1;
		}
		if (game->map->matrix[math->mapX][math->mapY] > '0')
			math->hit = 1;	
	}
}

static void	ft_calculate_ray_length(t_math_cub *math)
{
	if (math->raydirX < 0)
	{
		math->stepX = -1;
		math->sideDistX = (math->p_x - math->mapX) * math->deltaDistX;
	}
	else
	{
		math->stepX = 1;
		math->sideDistX = (math->mapX + 1.0 - math->p_x) * math->deltaDistX;
	}
	if (math->raydirY < 0)
	{
		math->stepY = -1;
		math->sideDistY = (math->p_y - math->mapY) * math->deltaDistY;
	}
	else
	{
		math->stepY = 1;
		math->sideDistY = (math->mapY + 1.0 - math->p_y) * math->deltaDistY;
	}
}

static void	ft_set_math_values(t_math_cub *math, int x)
{
	math->mapX = (int)math->p_x;
	math->mapY = (int)math->p_y;
	math->hit = 0;
	math->cameraX = 2 * x / (double)WIN_W - 1;
	math->raydirX = math->DirX + math->planeX * math->cameraX;
	math->raydirY = math->DirY + math->planeY * math->cameraX;
	math->deltaDistX = fabs(1 / math->raydirX);
	math->deltaDistY = fabs(1 / math->raydirY);
}