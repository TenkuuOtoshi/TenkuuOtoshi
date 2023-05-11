/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:41:17 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/08 13:58:04 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*ft_move_img(s_ptr *ptr, int h, int v, char c)
{
	if (ft_check_block(ptr, h, v) != 'O' && c == 'w')
		return (ptr->img_PU_ptr);
	if (ft_check_block(ptr, h, v) != 'O' && c == 's')
		return (ptr->img_PD_ptr);
	if (ft_check_block(ptr, h, v) != 'O' && c == 'a')
		return (ptr->img_PL_ptr);
	if (ft_check_block(ptr, h, v) != 'O' && c == 'd')
		return (ptr->img_PR_ptr);
	if (ft_check_block(ptr, h, v) == 'O' && c == 'w')
		return (ptr->img_PUC_ptr);
	if (ft_check_block(ptr, h, v) == 'O' && c == 's')
		return (ptr->img_PDC_ptr);
	if (ft_check_block(ptr, h, v) == 'O' && c == 'a')
		return (ptr->img_PLC_ptr);
	if (ft_check_block(ptr, h, v) == 'O' && c == 'd')
		return (ptr->img_PRC_ptr);
	return (0);
}

void	*ft_find_img(char c, s_ptr *ptr, int i, int y)
{
	if (c == 'C' && ptr->allow_map_change == 1)
	{
		ptr->map[y][i] = 'O';
		return (ptr->img_COS0_ptr);
	}
	if (c == 'O')
		return (ptr->img_COS0_ptr);
	if (c == '1')
		return (ptr->img_1_ptr);
	if (c == 'E')
	{
		if (ptr->end_allow != 1)
			ft_allow_end(ptr, i, y);
		return (ptr->img_EC_ptr);
	}
	if (c == 'C')
		return (ptr->img_CC_ptr);
	if (c == 'P')
		return (ft_player_spawn(i, y, ptr));
	if (c == 'M')
		return (ptr->img_M_ptr);
	return (ptr->img_0_ptr);
}

void	ft_check_death(s_ptr *ptr)
{
	if (ptr->map[ptr->pv / 48][ptr->ph / 48] == 'M')
	{
		printf("T'es mort");
		ft_free(ptr);
	}
}
