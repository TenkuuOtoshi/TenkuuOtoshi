/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monster_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:50:07 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/08 14:49:10 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_monster_sprite(s_ptr *ptr, int y, int i)
{
	if (ptr->monster_sprite_speed / 3333)
	{
		if (ptr->monster_state == 0)
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
				ptr->img_M_ptr, i * 48, y * 48);
		if (ptr->monster_state == 1)
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
				ptr->img_M1_ptr, i * 48, y * 48);
		if (ptr->monster_state == 2)
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
				ptr->img_M2_ptr, i * 48, y * 48);
	}
}

void	ft_monster(s_ptr *ptr)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (y <= ptr->y)
	{
		while (ptr->map[y][i] != '\0')
		{
			if (ptr->map[y][i] == 'M' && (y == 1 || y == 3 || y == 5 ||
				 y == 7 || y == 9 || y == 11 || y == 13 || y == 15 || y == 17))
				ft_monster_move(ptr, i, y);
			//if (ptr->map[y][i] == 'M' && (y == 2 || y == 4 || y == 6
			//	|| y == 8 || y == 10 || y == 12 || y == 14 || y == 16))
			//	return (0);
			i++;
		}
		i = 0;
		y++;
	}	
}

void	ft_monster_move(s_ptr *ptr, int i, int y)
{
	int	a;

	a = 1;
	if (ptr->monster_move_speed / 3333)
	{
		if (ptr->map[y][i - a] == '0')
		{
			ptr->map[y][i - a] = 'M';
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
				ptr->img_0_ptr, i * 48, y * 48);
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
				ptr->img_M_ptr, (i - a) * 48, y * 48);
			ptr->map[y][i] = '0';
		}
		else if (ptr->map[y][i + a] == '0')
		{
			ptr->map[y][i + a] = 'M';
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
				ptr->img_0_ptr, i * 48, y * 48);
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
				ptr->img_M_ptr, (i + a) * 48, y * 48);
			ptr->map[y][i] = '0';
		}
	}
}
