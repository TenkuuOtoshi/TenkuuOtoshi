/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:41:17 by tlarraze          #+#    #+#             */
/*   Updated: 2022/06/24 15:58:46 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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