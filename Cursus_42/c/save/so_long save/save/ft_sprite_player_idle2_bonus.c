/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_player_idle2_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:49:05 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/08 14:06:57 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_player_up_idle(s_ptr *ptr)
{
	if (ptr->player_state == 0 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PU_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 1 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PUS1_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 2 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PUS2_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 3 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PUS3_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 4 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PUS4_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 5 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PUS5_ptr, ptr->ph, ptr->pv);
}

void	ft_player_up_idle_chest(s_ptr *ptr)
{
	if (ptr->player_state == 0 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PUC_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 1 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PUCS1_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 2 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PUCS2_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 3 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PUCS3_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 4 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PUCS4_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 5 && ptr->p_side == 'w')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PUCS5_ptr, ptr->ph, ptr->pv);
}

void	ft_allow_end(s_ptr *ptr, int i, int y)
{
	ptr->eh = y * 48;
	ptr->ev = i * 48;
	ptr->end_allow = 1;
}
