/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:36:22 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/08 13:54:02 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free(s_ptr *ptr)
{
	int		i;

	i = 0;
	while (ptr->map[i] != NULL)
		free(ptr->map[i++]);
	free(ptr->map);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_0_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_EC_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_EO0_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_EO1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_CC_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_COS0_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PD_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PU_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PL_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PR_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PUC_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PLC_ptr);
	ft_free2(ptr);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	mlx_destroy_display(ptr->mlx_ptr);
	free(ptr->mlx_ptr);
	exit(0);
}

void	ft_free2(s_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_N0_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_N1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_N2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_N3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_N4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_N5_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_N6_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_N7_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_N8_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_N9_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_COS1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_COS2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_COS3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PRC_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PDC_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PDS1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PDS2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PDS3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PDS4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PDS5_ptr);
	ft_free3(ptr);
}

void	ft_free3(s_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PDCS1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PDCS2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PDCS3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PDCS4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PDCS5_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PLS1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PLS2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PLS3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PLS4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PLS5_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PLCS1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PLCS2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PLCS3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PLCS4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PLCS5_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PRCS1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PRCS2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PRCS3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PRCS4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PRCS5_ptr);
	ft_free4(ptr);
}

void	ft_free4(s_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PRS1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PRS2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PRS3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PRS4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PRS5_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PUS1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PUS2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PUS3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PUS4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PUS5_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PUCS1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PUCS2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PUCS3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PUCS4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PUCS5_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_M_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_M1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_M2_ptr);
}
