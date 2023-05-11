/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_img_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:39:43 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/11 15:57:17 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_load_img(t_ptr *ptr, int size)
{
	ptr->img_0_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/0.xpm", &size, &size);
	ptr->img_1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/1.xpm", &size, &size);
	ptr->img_ec_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/EC.xpm", &size, &size);
	ptr->img_eo0_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/EO0.xpm", &size, &size);
	ptr->img_eo1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/EO1.xpm", &size, &size);
	ptr->img_cc_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/CC.xpm", &size, &size);
	ptr->img_cos0_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/COS0.xpm", &size, &size);
	ptr->img_pd_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PD.xpm", &size, &size);
	ptr->img_pu_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PU.xpm", &size, &size);
	ptr->img_pl_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PL.xpm", &size, &size);
	ptr->img_pr_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PR.xpm", &size, &size);
	ptr->img_puc_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PUC.xpm", &size, &size);
	ft_load_img2(ptr, size);
}

void	ft_load_img2(t_ptr *ptr, int size)
{
	ptr->img_prc_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRC.xpm", &size, &size);
	ptr->img_pdc_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDC.xpm", &size, &size);
	ptr->img_n0_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N0.xpm", &size, &size);
	ptr->img_n1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N1.xpm", &size, &size);
	ptr->img_n2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N2.xpm", &size, &size);
	ptr->img_n3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N3.xpm", &size, &size);
	ptr->img_n4_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N4.xpm", &size, &size);
	ptr->img_n5_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N5.xpm", &size, &size);
	ptr->img_n6_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N6.xpm", &size, &size);
	ptr->img_n7_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N7.xpm", &size, &size);
	ptr->img_n8_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N8.xpm", &size, &size);
	ptr->img_n9_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/N9.xpm", &size, &size);
	ft_load_img3(ptr, size);
}

void	ft_load_img3(t_ptr *ptr, int size)
{
	ptr->img_cos1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/COS1.xpm", &size, &size);
	ptr->img_cos2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/COS2.xpm", &size, &size);
	ptr->img_cos3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/COS3.xpm", &size, &size);
	ptr->img_plc_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLC.xpm", &size, &size);
	ptr->img_pds1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDS1.xpm", &size, &size);
	ptr->img_pds2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDS2.xpm", &size, &size);
	ptr->img_pds3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDS3.xpm", &size, &size);
	ptr->img_pds4_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDS4.xpm", &size, &size);
	ptr->img_pds5_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDS5.xpm", &size, &size);
	ptr->img_pdcs1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDCS1.xpm", &size, &size);
	ptr->img_pdcs2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDCS2.xpm", &size, &size);
	ft_load_img4(ptr, size);
}

void	ft_load_img4(t_ptr *ptr, int size)
{
	ptr->img_pdcs3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDCS3.xpm", &size, &size);
	ptr->img_pdcs4_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDCS4.xpm", &size, &size);
	ptr->img_pdcs5_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDCS5.xpm", &size, &size);
	ptr->img_pls1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLS1.xpm", &size, &size);
	ptr->img_pls2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLS2.xpm", &size, &size);
	ptr->img_pls3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLS3.xpm", &size, &size);
	ptr->img_pls4_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLS4.xpm", &size, &size);
	ptr->img_pls5_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLS5.xpm", &size, &size);
	ptr->img_plcs1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLCS1.xpm", &size, &size);
	ptr->img_plcs2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLCS2.xpm", &size, &size);
	ptr->img_m1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/M1.xpm", &size, &size);
	ft_load_img5(ptr, size);
}

void	ft_load_img5(t_ptr *ptr, int size)
{
	ptr->img_plcs3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLCS3.xpm", &size, &size);
	ptr->img_plcs4_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLCS4.xpm", &size, &size);
	ptr->img_plcs5_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLCS5.xpm", &size, &size);
	ptr->img_prs1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRS1.xpm", &size, &size);
	ptr->img_prs2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRS2.xpm", &size, &size);
	ptr->img_prs3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRS3.xpm", &size, &size);
	ptr->img_prs4_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRS4.xpm", &size, &size);
	ptr->img_prs5_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRS5.xpm", &size, &size);
	ptr->img_prcs1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRCS1.xpm", &size, &size);
	ptr->img_prcs2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRCS2.xpm", &size, &size);
	ptr->img_prcs3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRCS3.xpm", &size, &size);
	ft_load_img6(ptr, size);
}
