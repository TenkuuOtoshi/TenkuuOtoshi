/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_img_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:39:43 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/08 14:00:20 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_load_img(s_ptr *ptr, int size)
{
	ptr->img_0_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/0.xpm", &size, &size);
	ptr->img_1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/1.xpm", &size, &size);
	ptr->img_EC_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/EC.xpm", &size, &size);
	ptr->img_EO0_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/EO0.xpm", &size, &size);
	ptr->img_EO1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/EO1.xpm", &size, &size);
	ptr->img_CC_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/CC.xpm", &size, &size);
	ptr->img_COS0_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/COS0.xpm", &size, &size);
	ptr->img_PD_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PD.xpm", &size, &size);
	ptr->img_PU_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PU.xpm", &size, &size);
	ptr->img_PL_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PL.xpm", &size, &size);
	ptr->img_PR_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PR.xpm", &size, &size);
	ptr->img_PUC_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PUC.xpm", &size, &size);
	ft_load_img2(ptr, size);
}

void	ft_load_img2(s_ptr *ptr, int size)
{
	ptr->img_PRC_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRC.xpm", &size, &size);
	ptr->img_PDC_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDC.xpm", &size, &size);
	ptr->img_N0_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N0.xpm", &size, &size);
	ptr->img_N1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N1.xpm", &size, &size);
	ptr->img_N2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N2.xpm", &size, &size);
	ptr->img_N3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N3.xpm", &size, &size);
	ptr->img_N4_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N4.xpm", &size, &size);
	ptr->img_N5_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N5.xpm", &size, &size);
	ptr->img_N6_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N6.xpm", &size, &size);
	ptr->img_N7_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N7.xpm", &size, &size);
	ptr->img_N8_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N8.xpm", &size, &size);
	ptr->img_N9_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N9.xpm", &size, &size);
	ft_load_img3(ptr, size);
}

void	ft_load_img3(s_ptr *ptr, int size)
{
	ptr->img_COS1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/COS1.xpm", &size, &size);
	ptr->img_COS2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/COS2.xpm", &size, &size);
	ptr->img_COS3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/COS3.xpm", &size, &size);
	ptr->img_PLC_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLC.xpm", &size, &size);
	ptr->img_PDS1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDS1.xpm", &size, &size);
	ptr->img_PDS2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDS2.xpm", &size, &size);
	ptr->img_PDS3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDS3.xpm", &size, &size);
	ptr->img_PDS4_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDS4.xpm", &size, &size);
	ptr->img_PDS5_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDS5.xpm", &size, &size);
	ptr->img_PDCS1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDCS1.xpm", &size, &size);
	ptr->img_PDCS2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDCS2.xpm", &size, &size);
	ft_load_img4(ptr, size);
}

void	ft_load_img4(s_ptr *ptr, int size)
{
	ptr->img_PDCS3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDCS3.xpm", &size, &size);
	ptr->img_PDCS4_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDCS4.xpm", &size, &size);
	ptr->img_PDCS5_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDCS5.xpm", &size, &size);
	ptr->img_PLS1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLS1.xpm", &size, &size);
	ptr->img_PLS2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLS2.xpm", &size, &size);
	ptr->img_PLS3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLS3.xpm", &size, &size);
	ptr->img_PLS4_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLS4.xpm", &size, &size);
	ptr->img_PLS5_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLS5.xpm", &size, &size);
	ptr->img_PLCS1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLCS1.xpm", &size, &size);
	ptr->img_PLCS2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLCS2.xpm", &size, &size);
	ptr->img_M1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/M1.xpm", &size, &size);
	ft_load_img5(ptr, size);
}

void	ft_load_img5(s_ptr *ptr, int size)
{
	ptr->img_PLCS3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLCS3.xpm", &size, &size);
	ptr->img_PLCS4_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLCS4.xpm", &size, &size);
	ptr->img_PLCS5_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLCS5.xpm", &size, &size);
	ptr->img_PRS1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRS1.xpm", &size, &size);
	ptr->img_PRS2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRS2.xpm", &size, &size);
	ptr->img_PRS3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRS3.xpm", &size, &size);
	ptr->img_PRS4_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRS4.xpm", &size, &size);
	ptr->img_PRS5_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRS5.xpm", &size, &size);
	ptr->img_PRCS1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRCS1.xpm", &size, &size);
	ptr->img_PRCS2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRCS2.xpm", &size, &size);
	ptr->img_PRCS3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRCS3.xpm", &size, &size);
	ft_load_img6(ptr, size);
}
