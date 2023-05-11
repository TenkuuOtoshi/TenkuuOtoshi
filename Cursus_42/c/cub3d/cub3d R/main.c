/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:20:09 by tlarraze          #+#    #+#             */
/*   Updated: 2023/02/26 14:34:50 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3d.h"

void	ft_put_pixel_circle(void *ptr, void *win, int x, int y, int color)
{
	int	end_y;
	int	end_x;
	int	middle_x;
	int	middle_y;

	middle_x = x;
	middle_y = y;
	end_x = x + 8;
	end_y = y - 6;
	x = x - 8;
	y = y + 7;
	while (y != end_y || x != end_x)
	{
		while (x != end_x)
		{
			if ((y == middle_y + 6 || y == middle_y - 6) && ( x < middle_x + 2 && x > middle_x - 2))
					mlx_pixel_put(ptr, win, x, y, color);
			if ((y == middle_y + 5 || y == middle_y - 5) && (x == middle_x + 2 || x == middle_x - 2))
					mlx_pixel_put(ptr, win, x, y, color);
			if ((y == middle_y + 5 || y == middle_y - 5) && ( x == middle_x + 3 || x == middle_x - 3))
					mlx_pixel_put(ptr, win, x, y, color);
			if ((y == middle_y + 4 || y == middle_y - 4) && ( x == middle_x + 4 || x == middle_x - 4))
					mlx_pixel_put(ptr, win, x, y, color);
			if ((y == middle_y + 3 || y == middle_y - 3) && ( x == middle_x + 5 || x == middle_x - 5))
					mlx_pixel_put(ptr, win, x, y, color);
			if ((y == middle_y + 2 || y == middle_y - 2) && ( x == middle_x + 5 || x == middle_x - 5))
					mlx_pixel_put(ptr, win, x, y, color);
			if ((y == middle_y + 1 || y == middle_y - 1) && ( x == middle_x + 6 || x == middle_x - 6))
					mlx_pixel_put(ptr, win, x, y, color);
			if (y == middle_y && ( x == middle_x + 6 || x == middle_x - 6))
					mlx_pixel_put(ptr, win, x, y, color);
		x++;
		}
		if (y != end_y)
		{
			x = middle_x - 8;
			y--;
		}
		
	}
}

int	use_key(int key, t_ptr *ptr)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
		mlx_destroy_display(ptr->mlx_ptr);
		free(ptr->mlx_ptr);
		exit(0);
	}
	if ((key == XK_w || key == XK_Up) && ptr->p_y - 10 > 0)
	{
		ft_put_pixel_circle(ptr->mlx_ptr, ptr->win_ptr, ptr->p_x / 2, ptr->p_y / 2, 0);
		ptr->p_y -= 10;
		ft_put_pixel_circle(ptr->mlx_ptr, ptr->win_ptr, ptr->p_x / 2, ptr->p_y / 2, 0x2FEB99);
	}
	if ((key == XK_a || key == XK_Left) && ptr->p_x - 10 > 0)
	{
		ft_put_pixel_circle(ptr->mlx_ptr, ptr->win_ptr, ptr->p_x / 2, ptr->p_y / 2, 0);
		ptr->p_x -= 10;
		ft_put_pixel_circle(ptr->mlx_ptr, ptr->win_ptr, ptr->p_x / 2, ptr->p_y / 2, 0x2FEB99);
	}
	if ((key == XK_d || key == XK_Right) && ptr->p_x + 10 < 1920 * 2) //too look it's weird
	{
		ft_put_pixel_circle(ptr->mlx_ptr, ptr->win_ptr, ptr->p_x / 2, ptr->p_y / 2, 0);
		ptr->p_x += 10;
		ft_put_pixel_circle(ptr->mlx_ptr, ptr->win_ptr, ptr->p_x / 2, ptr->p_y / 2, 0x2FEB99);
	}
	if ((key == XK_s || key == XK_Down) && ptr->p_y + 10 < 1920)
	{
		ft_put_pixel_circle(ptr->mlx_ptr, ptr->win_ptr, ptr->p_x / 2, ptr->p_y / 2, 0);
		ptr->p_y += 10;
		ft_put_pixel_circle(ptr->mlx_ptr, ptr->win_ptr, ptr->p_x / 2, ptr->p_y / 2, 0x2FEB99);
	}
	return (0);
}

void	ft_put_pixel_square(t_ptr *ptr, int color)
{
	int	x;
	int	y;
	int	i;
	int j;

	i = 0;
	j = 0;
	x = 0 + 32;
	y = 0 + 32;
	while (j <= 256)
	{
		while (i <= 256)
		{
			if (i == 256 || i == 0 || j == 0 || j == 256)
				mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, x + i, y + j, color);
			i++;
		}
		i = 0;
		j++;
		x = 0 + 32;
	}
	i = 0;
	j = 0;
	x = 0 + 32;
	y = 0 + 32;
	while (j <= 257)
	{
		while (i <= 257)
		{
			if (i == 257 || i == 1 || j == 1 || j == 257)
				mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, x + i, y + j, color);
			i++;
		}
		i = 0;
		j++;
		x = 0 + 32;
	}
	i = 0;
	j = 0;
	x = 0 + 32;
	y = 0 + 32;
	while (j <= 258)
	{
		while (i <= 258)
		{
			if (i == 258 || i == 2 || j == 2 || j == 258)
				mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, x + i, y + j, color);
			i++;
		}
		i = 0;
		j++;
		x = 0 + 32;
	}
}

void	ft_put_circle_2(t_ptr *ptr, int cx, int cy, int r)
{
	int	x;
	int	y;

	x = 0;
	y = r;
	while (x <= y)
	{
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, cx + x, cy + y, 0x2FEB99);
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, cx + x, cy - y, 0x2FEB99);
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, cx - x, cy + y, 0x2FEB99);
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, cx - x, cy - y, 0x2FEB99);
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, cx + y, cy + x, 0x2FEB99);
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, cx + y, cy - x, 0x2FEB99);
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, cx - y, cy + x, 0x2FEB99);
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, cx - y, cy - x, 0x2FEB99);
		x++;
		if (sqrt(x * x + y * y) > r)
			y--;
	}
}

int	main()
{
	t_ptr	ptr;

	ptr.p_x = 1920;
	ptr.p_y = 1080;
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, ptr.p_x, ptr.p_y, "Cub3d Baby !");
	ft_put_circle_2(&ptr, ptr.p_x / 2, ptr.p_y / 2, 17);
	ft_put_pixel_square(&ptr, 0x2FEB99);
	ft_put_circle_2(&ptr, 151, 151, 128);
	mlx_hook(ptr.win_ptr, 2, 1L << 0, use_key, &ptr);
	mlx_loop(ptr.mlx_ptr);
	//mlx_hook();

}

