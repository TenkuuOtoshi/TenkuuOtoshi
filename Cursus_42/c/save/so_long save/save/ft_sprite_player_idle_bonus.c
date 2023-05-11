/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_player_idle_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:45:43 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/08 14:03:47 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_player_down_idle(s_ptr *ptr)
{
	if (ptr->player_state == 0 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PD_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 1 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PDS1_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 2 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PDS2_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 3 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PDS3_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 4 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PDS4_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 5 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PDS5_ptr, ptr->ph, ptr->pv);
}

void	ft_player_down_idle_chest(s_ptr *ptr)
{
	if (ptr->player_state == 0 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PDC_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 1 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PDCS1_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 2 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PDCS2_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 3 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PDCS3_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 4 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PDCS4_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 5 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PDCS5_ptr, ptr->ph, ptr->pv);
}

void	ft_player_left_idle(s_ptr *ptr)
{
	if (ptr->player_state == 0 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PL_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 1 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PLS1_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 2 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PLS2_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 3 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PLS3_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 4 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PLS4_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 5 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PLS5_ptr, ptr->ph, ptr->pv);
}

void	ft_player_left_idle_chest(s_ptr *ptr)
{
	if (ptr->player_state == 0 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PLC_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 1 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PLCS1_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 2 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PLCS2_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 3 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PLCS3_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 4 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PLCS4_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 5 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PLCS5_ptr, ptr->ph, ptr->pv);
}

void	ft_player_right_idle(s_ptr *ptr)
{
	if (ptr->player_state == 0 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PR_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 1 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PRS1_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 2 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PRS2_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 3 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PRS3_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 4 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PRS4_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 5 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_PRS5_ptr, ptr->ph, ptr->pv);
}
