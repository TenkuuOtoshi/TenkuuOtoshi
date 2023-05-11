/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_player_idle_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:45:43 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/11 15:59:57 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_player_down_idle(t_ptr *ptr)
{
	if (ptr->player_state == 0 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pd_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 1 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pds1_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 2 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pds2_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 3 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pds3_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 4 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pds4_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 5 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pds5_ptr, ptr->ph, ptr->pv);
}

void	ft_player_down_idle_chest(t_ptr *ptr)
{
	if (ptr->player_state == 0 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pdc_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 1 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pdcs1_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 2 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pdcs2_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 3 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pdcs3_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 4 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pdcs4_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 5 && ptr->p_side == 's')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pdcs5_ptr, ptr->ph, ptr->pv);
}

void	ft_player_left_idle(t_ptr *ptr)
{
	if (ptr->player_state == 0 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pl_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 1 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pls1_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 2 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pls2_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 3 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pls3_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 4 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pls4_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 5 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pls5_ptr, ptr->ph, ptr->pv);
}

void	ft_player_left_idle_chest(t_ptr *ptr)
{
	if (ptr->player_state == 0 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_plc_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 1 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_plcs1_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 2 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_plcs2_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 3 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_plcs3_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 4 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_plcs4_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 5 && ptr->p_side == 'a')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_plcs5_ptr, ptr->ph, ptr->pv);
}

void	ft_player_right_idle(t_ptr *ptr)
{
	if (ptr->player_state == 0 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_pr_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 1 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_prs1_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 2 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_prs2_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 3 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_prs3_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 4 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_prs4_ptr, ptr->ph, ptr->pv);
	if (ptr->player_state == 5 && ptr->p_side == 'd')
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_prs5_ptr, ptr->ph, ptr->pv);
}
