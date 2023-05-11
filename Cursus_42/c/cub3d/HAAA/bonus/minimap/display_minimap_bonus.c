#include "cub3D_bonus.h"

/*
divise le cercle en 4 quarts.
top left = player_pos - x player_pos - y
top right = player_pos + x player_pos - y
bottom left = player_pos - x player_pos + y
bottom right = player_pos + x player_pos + y
*/

static void	draw_minimap_player(t_img_cub *screen)
{
	int	center_x;
	int	center_y;
	int	x;
	int	y;

	center_x = MINMAP_W / 2;
	center_y = MINMAP_H / 2;
/*	y = (MINMAP_H / 2) - MINMAP_PLAYER_R;
	x = (MINMAP_H / 2) - MINMAP_PLAYER_R;
	my_mlx_pixel_put(minimap, x, y, convert_rgb_into_int(pink_rgb));
	
	y = (MINMAP_H / 2) - MINMAP_PLAYER_R;
	x = (MINMAP_H / 2) + MINMAP_PLAYER_R;
	my_mlx_pixel_put(minimap, x, y, convert_rgb_into_int(pink_rgb));
	
	y = (MINMAP_H / 2) + MINMAP_PLAYER_R;
	x = (MINMAP_H / 2) - MINMAP_PLAYER_R;
	my_mlx_pixel_put(minimap, x, y, convert_rgb_into_int(pink_rgb));
	
	y = (MINMAP_H / 2) + MINMAP_PLAYER_R;
	x = (MINMAP_H / 2) + MINMAP_PLAYER_R;
	my_mlx_pixel_put(minimap, x, y, convert_rgb_into_int(pink_rgb));*/
	y = (MINMAP_H / 2) - MINMAP_PLAYER_R;
	while (y < (MINMAP_H / 2) + MINMAP_PLAYER_R)
	{
		x = (MINMAP_H / 2) - MINMAP_PLAYER_R;
		while (x < (MINMAP_H / 2) + MINMAP_PLAYER_R)
		{
			if (round(sqrt(pow(x - center_x, 2) + pow(y - center_y, 2))) < MINMAP_PLAYER_R)
				my_mlx_pixel_put(screen, 20 + x, 20 + y, ORANGE);
			x++;
		}
		y++;
	}
}

/*static void	draw_minimap_border(t_img_cub *minimap, t_img_cub *minimap_border, t_game_cub *game)
{
	int	y;
	int	x;
	int	colour;

	y = 0;
	while (y < minimap_border->height)
	{
		x = 0;
		while (x < minimap_border->width)
		{
			colour = get_pixel(game->minimap_border, x, y);
			if (colour == GREEN_SCREEN)
			{
				x++;
				continue ;
			}
			else
				my_mlx_pixel_put(minimap, x, y, colour);
			x++;
		}
		y++;
	}
}*/

static void	draw_minimap_player_ray(t_img_cub *screen, t_game_cub *game)
{
    double	end_x;
    double	end_y;
    double	dx;
    double	dy;
    double	center_x;
    double	center_y;
    int		px_length;

    center_x = MINMAP_W / 2;
    center_y = MINMAP_H / 2;
    end_x = center_x + MINMAP_LEN_RAY * game->math->DirX;
    end_y = center_y + MINMAP_LEN_RAY * game->math->DirY;
    dx = (end_x - center_x);
    dy = (end_y - center_y);
    px_length = sqrt((dx * dx) + (dy * dy));
    dx /= px_length;
    dy /= px_length;
	while (px_length)
	{
		my_mlx_pixel_put(screen, 20 + center_x, 20 + center_y, PURPLE);
		center_x += dx;
		center_y += dy;
		px_length--;
	}
}

static void	draw_minimap_circle(t_img_cub *screen, t_game_cub *game)
{
	int	y;
	int	x;
	int	center_x;
	int	center_y;
	int	value;
	int	colour;

	center_x = MINMAP_W / 2;
	center_y = MINMAP_H / 2;
	y = 0;
	while (y < MINMAP_H)
	{
		x = 0;
		while (x < MINMAP_W)
		{
			value = round(sqrt(pow(x - center_x, 2)
				+ pow(y - center_y, 2)));
			if (value == MINMAP_R - 1 || value == MINMAP_R - 2)
				my_mlx_pixel_put(screen, 20 + x, 20 + y, ORANGE);//circle
			else if (value < MINMAP_R - 1)
			{
				colour = get_matrix_coord_colour(game, x, y);
				my_mlx_pixel_put(screen, 20 + x, 20 + y, colour);//circle content
			}
			x++;
		}
		y++;
	}
//	colour = get_coord_colour(game, 216, 500);
}

static void	draw_minimap(t_game_cub *game)
{
	draw_minimap_circle(game->mlx->screen, game);
//	draw_minimap_border(game->minimap, game->minimap_border, game);
    draw_minimap_player_ray(game->mlx->screen, game);
	draw_minimap_player(game->mlx->screen);
}

static void	print_minimap(t_game_cub *game)
{
	draw_minimap(game);
/*	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
		game->mlx->screen->img, 0, 0);*/
}

int	display_minimap(t_game_cub *game)
{
//	game->minimap = init_minimap(game->mlx);
//	game->mlx->minimap_border = init_minimap_border("./textures/map_border.xpm", game->mlx);
	if (/*game->minimap == NULL || */game->mlx->screen == NULL/* || game->mlx->minimap_border == NULL*/)
		return (1);
	print_minimap(game);
	return (0);
}
