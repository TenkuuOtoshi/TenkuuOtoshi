/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:41:17 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/11 17:38:27 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*ft_move_img(t_ptr *ptr, int h, int v, char c)
{
	if (ft_check_block(ptr, h, v) != 'O' && c == 'w' && ptr->death == 0)
		return (ptr->img_pu_ptr);
	if (ft_check_block(ptr, h, v) != 'O' && c == 's' && ptr->death == 0)
		return (ptr->img_pd_ptr);
	if (ft_check_block(ptr, h, v) != 'O' && c == 'a' && ptr->death == 0)
		return (ptr->img_pl_ptr);
	if (ft_check_block(ptr, h, v) != 'O' && c == 'd' && ptr->death == 0)
		return (ptr->img_pr_ptr);
	if (ft_check_block(ptr, h, v) == 'O' && c == 'w' && ptr->death == 0)
		return (ptr->img_puc_ptr);
	if (ft_check_block(ptr, h, v) == 'O' && c == 's' && ptr->death == 0)
		return (ptr->img_pdc_ptr);
	if (ft_check_block(ptr, h, v) == 'O' && c == 'a' && ptr->death == 0)
		return (ptr->img_plc_ptr);
	if (ft_check_block(ptr, h, v) == 'O' && c == 'd' && ptr->death == 0)
		return (ptr->img_prc_ptr);
	return (0);
}

void	*ft_find_img(char c, t_ptr *ptr, int i, int y)
{
	if (c == 'C' && ptr->allow_map_change == 1)
	{
		ptr->map[y][i] = 'O';
		return (ptr->img_cos0_ptr);
	}
	if (c == 'O')
		return (ptr->img_cos0_ptr);
	if (c == '1')
		return (ptr->img_1_ptr);
	if (c == 'E')
	{
		if (ptr->end_allow != 1)
			ft_allow_end(ptr, i, y);
		return (ptr->img_ec_ptr);
	}
	if (c == 'C')
		return (ptr->img_cc_ptr);
	if (c == 'P')
		return (ft_player_spawn(i, y, ptr));
	if (c == 'M')
		return (ptr->img_m_ptr);
	if (c == '0' && ptr->death == 0)
		return (ptr->img_0_ptr);
	return (ptr->img_0_ptr);
}

void	ft_check_death(t_ptr *ptr)
{
	if (ptr->map[ptr->pv / 48][ptr->ph / 48] == 'M' ||
		ptr->map[ptr->pv / 48][ptr->ph / 48] == 'W')
	{
		if (ptr->death != 1)
		{
			mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_gm_ptr,
				(ft_strlen(ptr->map[0])) * 48 / 2 - 48,
				(ft_window_size(ptr->map_name, 'v', ptr) / 2) - 96);
		}
		ptr->death = 1;
	}
}
