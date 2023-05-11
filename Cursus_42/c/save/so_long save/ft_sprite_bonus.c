/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:12:53 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/11 15:27:03 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_chest_sprite(t_ptr *ptr)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	ptr->sprite_speed++;
	ptr->monster_sprite_speed++;
	ft_check_death(ptr);
	ft_monster(ptr);
	ft_player_sprite(ptr);
	while (y <= ptr->y && ptr->death == 0)
	{
		while (ptr->map[y][i] != '\0')
		{
			if (ptr->map[y][i] == 'O')
				ft_put_sprite(ptr, y, i);
			if (ptr->map[y][i] == 'M' || ptr->map[y][i] == 'W')
				ft_monster_sprite(ptr, y, i);
			i++;
		}
		i = 0;
		y++;
	}
	ft_restart_state_speed(ptr);
	return (0);
}

void	ft_put_sprite(t_ptr *ptr, int y, int i)
{
	if (ptr->sprite_speed / 3333 && ptr->death == 0)
	{
		if (ptr->chest_state == 0 && (ptr->ph / 48 != i || ptr->pv / 48 != y))
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
				ptr->img_cos0_ptr, i * 48, y * 48);
		if (ptr->chest_state == 1 && (ptr->ph / 48 != i || ptr->pv / 48 != y))
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
				ptr->img_cos1_ptr, i * 48, y * 48);
		if (ptr->chest_state == 2 && (ptr->ph / 48 != i || ptr->pv / 48 != y))
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
				ptr->img_cos2_ptr, i * 48, y * 48);
		if (ptr->chest_state == 3 && (ptr->ph / 48 != i || ptr->pv / 48 != y))
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
				ptr->img_cos3_ptr, i * 48, y * 48);
	}
}

void	ft_player_sprite(t_ptr *ptr)
{
	if (ptr->player_sprite_speed / 3000 && ptr->death == 0)
	{
		if (ptr->map[ptr->pv / 48][ptr->ph / 48] != 'O' && ptr->p_side == 's')
			ft_player_down_idle(ptr);
		if (ptr->map[ptr->pv / 48][ptr->ph / 48] == 'O' && ptr->p_side == 's')
			ft_player_down_idle_chest(ptr);
		if (ptr->map[ptr->pv / 48][ptr->ph / 48] != 'O' && ptr->p_side == 'a')
			ft_player_left_idle(ptr);
		if (ptr->map[ptr->pv / 48][ptr->ph / 48] == 'O' && ptr->p_side == 'a')
			ft_player_left_idle_chest(ptr);
		if (ptr->map[ptr->pv / 48][ptr->ph / 48] != 'O' && ptr->p_side == 'd')
			ft_player_right_idle(ptr);
		if (ptr->map[ptr->pv / 48][ptr->ph / 48] == 'O' && ptr->p_side == 'd')
			ft_player_right_idle_chest(ptr);
		if (ptr->map[ptr->pv / 48][ptr->ph / 48] != 'O' && ptr->p_side == 'w')
			ft_player_up_idle(ptr);
		if (ptr->map[ptr->pv / 48][ptr->ph / 48] == 'O' && ptr->p_side == 'w')
			ft_player_up_idle_chest(ptr);
		ptr->player_sprite_speed = 0;
		ptr->player_state++;
	}
	if (ptr->player_state == 6)
		ptr->player_state = -1;
	ptr->player_sprite_speed++;
}

void	ft_restart_state_speed(t_ptr *ptr)
{
	if (ptr->chest_state == 3)
		ptr->chest_state = -1;
	if (ptr->monster_state == 2)
		ptr->monster_state = -1;
	ptr->monster_state++;
	ptr->chest_state++;
	ptr->monster_move_speed++;
	if (ptr->end == 1 && ptr->sprite_speed / 3333)
		ft_exit_sprite(ptr);
	if (ptr->sprite_speed / 3333)
		ptr->sprite_speed = 0;
	if (ptr->monster_sprite_speed / 3334)
		ptr->monster_sprite_speed = 0;
	if (ptr->monster_move_speed / 3334)
		ptr->monster_move_speed = 0;
}

void	ft_player_right_idle_chest(t_ptr *ptr)
{
	if (ptr->player_state == 0 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_prc_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 1 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_prcs1_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 2 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_prcs2_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 3 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_prcs3_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 4 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_prcs4_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 5 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_prcs5_ptr, ptr->ph, ptr->pv);
}
