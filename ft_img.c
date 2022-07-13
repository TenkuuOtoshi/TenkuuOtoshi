/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:41:17 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/11 15:18:18 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_move_img(t_ptr *ptr, int h, int v, char c)
{
	if (ft_check_block(ptr, h, v) != 'O' && c == 'w')
		return (ptr->img_pu_ptr);
	if (ft_check_block(ptr, h, v) != 'O' && c == 's')
		return (ptr->img_pd_ptr);
	if (ft_check_block(ptr, h, v) != 'O' && c == 'a')
		return (ptr->img_pl_ptr);
	if (ft_check_block(ptr, h, v) != 'O' && c == 'd')
		return (ptr->img_pr_ptr);
	if (ft_check_block(ptr, h, v) == 'O' && c == 'w')
		return (ptr->img_puc_ptr);
	if (ft_check_block(ptr, h, v) == 'O' && c == 's')
		return (ptr->img_pdc_ptr);
	if (ft_check_block(ptr, h, v) == 'O' && c == 'a')
		return (ptr->img_plc_ptr);
	if (ft_check_block(ptr, h, v) == 'O' && c == 'd')
		return (ptr->img_prc_ptr);
	return (0);
}

void	ft_load_img(t_ptr *ptr, int size)
{
	ptr->img_0_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/0.xpm", &size, &size);
	ptr->img_1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/1.xpm", &size, &size);
	ptr->img_ec_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/EC.xpm", &size, &size);
	ptr->img_eo1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/EO1.xpm", &size, &size);
	ptr->img_cc_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/CC.xpm", &size, &size);
	ptr->img_co_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/COS0.xpm", &size, &size);
	ptr->img_pd_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PD.xpm", &size, &size);
	ft_load_img2(ptr, size);
}

void	ft_load_img2(t_ptr *ptr, int size)
{
	ptr->img_pu_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PU.xpm", &size, &size);
	ptr->img_pl_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PL.xpm", &size, &size);
	ptr->img_pr_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PR.xpm", &size, &size);
	ptr->img_puc_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PUC.xpm", &size, &size);
	ptr->img_plc_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLC.xpm", &size, &size);
	ptr->img_prc_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRC.xpm", &size, &size);
	ptr->img_pdc_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDC.xpm", &size, &size);
}

void	*ft_find_img(char c, t_ptr *ptr, int i, int y)
{
	if (c == 'C' && ptr->allow_map_change == 1)
	{
		ptr->map[y][i] = 'O';
		return (ptr->img_co_ptr);
	}
	if (c == 'O')
		return (ptr->img_co_ptr);
	if (c == '1')
		return (ptr->img_1_ptr);
	if (c == 'E')
	{
		if (ptr->end_allow != 1)
		{
			ptr->eh = y * 48;
			ptr->ev = i * 48;
			ptr->end_allow = 1;
		}
		return (ptr->img_ec_ptr);
	}
	if (c == 'C')
		return (ptr->img_cc_ptr);
	if (c == 'P')
		return (ft_player_spawn(i, y, ptr));
	return (ptr->img_0_ptr);
}

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
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_eo1_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_cc_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_co_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pd_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pu_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pl_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pr_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_puc_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_plc_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_prc_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_pdc_ptr);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	mlx_destroy_display(ptr->mlx_ptr);
	free(ptr->mlx_ptr);
	exit(0);
}
