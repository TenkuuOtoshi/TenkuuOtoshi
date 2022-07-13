/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:36:22 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/11 17:33:01 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free(t_ptr *ptr)
{
	int		i;

	i = 0;
	while (ptr->map[i] != NULL)
		free(ptr->map[i++]);
	free(ptr->map);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_0_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_ec_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_eo0_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_eo1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_cc_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_cos0_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pd_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pu_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pl_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pr_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_puc_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_plc_ptr);
	ft_free2(ptr);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	mlx_destroy_display(ptr->mlx_ptr);
	free(ptr->mlx_ptr);
	exit(0);
}

void	ft_free2(t_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_n0_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_n1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_n2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_n3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_n4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_n5_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_n6_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_n7_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_n8_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_n9_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_cos1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_cos2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_cos3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_prc_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pdc_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pds1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pds2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pds3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pds4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pds5_ptr);
	ft_free3(ptr);
}

void	ft_free3(t_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pdcs1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pdcs2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pdcs3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pdcs4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pdcs5_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pls1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pls2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pls3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pls4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pls5_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_plcs1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_plcs2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_plcs3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_plcs4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_plcs5_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_prcs1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_prcs2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_prcs3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_prcs4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_prcs5_ptr);
	ft_free4(ptr);
}

void	ft_free4(t_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_prs1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_prs2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_prs3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_prs4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_prs5_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pus1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pus2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pus3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pus4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pus5_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pucs1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pucs2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pucs3_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pucs4_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pucs5_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_m_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_m1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_m2_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_gm_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_dark_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_win_ptr);
}
