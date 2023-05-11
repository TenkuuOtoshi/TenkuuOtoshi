/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monster_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:50:07 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/11 16:39:31 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_monster_sprite(t_ptr *ptr, int y, int i)
{
	if (ptr->monster_sprite_speed / 3333 && ptr->death == 0)
	{
		if (ptr->monster_state == 0)
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
				ptr->img_m_ptr, i * 48, y * 48);
		if (ptr->monster_state == 1)
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
				ptr->img_m1_ptr, i * 48, y * 48);
		if (ptr->monster_state == 2)
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
				ptr->img_m2_ptr, i * 48, y * 48);
	}
}

void	ft_monster(t_ptr *ptr)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (y <= ptr->y && ptr->death == 0)
	{
		while (ptr->map[y][i] != '\0')
		{
			if (ptr->map[y][i] == 'M' || ptr->map[y][i] == 'W')
			{
				ptr->monster_side = ft_monster_move(ptr, i, y);
				i++;
			}
			i++;
		}
		i = 0;
		y++;
	}
	ptr->monster_side = -1;
}

int	ft_monster_move(t_ptr *ptr, int i, int y)
{
	ft_check_death(ptr);
	if (ptr->monster_side != -1 && ptr->death == 0)
		return (ft_assign_side(ptr, i, y));
	if (ptr->monster_move_speed / 3333 && ptr->monster_side == -1
		&& ptr->death == 0)
	{
		if (ptr->map[y][i] == 'M')
			ft_monster_move_left(ptr, i, y);
		if (ptr->map[y][i] == 'W')
			ft_monster_move_right(ptr, i, y);
	}
	return (-1);
}

int	ft_assign_side(t_ptr *ptr, int i, int y)
{
	if (ptr->monster_side == 1)
		ptr->map[y][i] = 'W';
	if (ptr->monster_side == 1)
		return (0);
	if (ptr->monster_side == 0)
		return (1);
	return (-1);
}

void	ft_monster_move_left(t_ptr *ptr, int i, int y)
{
	if (ptr->map[y][i - 1] != '0')
		ptr->map[y][i] = 'W';
	if (ptr->map[y][i - 1] == '0' && ptr->death == 0)
	{
		ft_check_death(ptr);
		ptr->map[y][i - 1] = 'M';
		ptr->map[y][i] = '0';
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_0_ptr,
			i * 48, y * 48);
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_m_ptr,
			(i - 1) * 48, y * 48);
	}
}
