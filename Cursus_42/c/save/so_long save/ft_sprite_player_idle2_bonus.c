/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_player_idle2_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:49:05 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/11 16:39:49 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_player_up_idle(t_ptr *ptr)
{
	if (ptr->player_state == 0 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pu_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 1 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pus1_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 2 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pus2_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 3 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pus3_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 4 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pus4_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 5 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pus5_ptr, ptr->ph, ptr->pv);
}

void	ft_player_up_idle_chest(t_ptr *ptr)
{
	if (ptr->player_state == 0 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_puc_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 1 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pucs1_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 2 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pucs2_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 3 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pucs3_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 4 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pucs4_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 5 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pucs5_ptr, ptr->ph, ptr->pv);
}

void	ft_allow_end(t_ptr *ptr, int i, int y)
{
	ptr->eh = y * 48;
	ptr->ev = i * 48;
	ptr->end_allow = 1;
}

void	ft_monster_move_right(t_ptr *ptr, int i, int y)
{
	if (ptr->map[y][i + 1] != '0')
		ptr->map[y][i] = 'M';
	if (ptr->map[y][i + 1] == '0')
	{
		ptr->map[y][i + 1] = 'W';
		ptr->map[y][i] = '0';
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_0_ptr,
			i * 48, y * 48);
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_m_ptr,
			(i + 1) * 48, y * 48);
	}
}
