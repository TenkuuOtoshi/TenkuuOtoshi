/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:41:17 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/04 14:40:53 by tlarraze         ###   ########.fr       */
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

void	ft_load_img(s_ptr *ptr, int size)
{
	ptr->img_0_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/0.xpm", &size, &size);
	ptr->img_1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/1.xpm", &size, &size);
	ptr->img_EC_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/EC.xpm", &size, &size);
	ptr->img_EO_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/EO.xpm", &size, &size);
	ptr->img_CC_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/CC.xpm", &size, &size);
	ptr->img_CO_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/CO.xpm", &size, &size);
	ptr->img_PD_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PD.xpm", &size, &size);
	ft_load_img2(ptr, size);
}

void	ft_load_img2(s_ptr *ptr, int size)
{
	ptr->img_PU_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PU.xpm", &size, &size);
	ptr->img_PL_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PL.xpm", &size, &size);
	ptr->img_PR_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PR.xpm", &size, &size);
	ptr->img_PUC_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PUC.xpm", &size, &size);
	ptr->img_PLC_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PLC.xpm", &size, &size);
	ptr->img_PRC_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRC.xpm", &size, &size);
	ptr->img_PDC_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PDC.xpm", &size, &size);
}

void	*ft_find_img(char c, s_ptr *ptr, int i, int y)
{
	if (c == 'C' && ptr->allow_map_change == 1)
	{
		ptr->map[y][i] = 'O';
		return (ptr->img_CO_ptr);
	}
	if (c == 'O')
		return (ptr->img_CO_ptr);
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
		return (ptr->img_EC_ptr);
	}
	if (c == 'C')
		return (ptr->img_CC_ptr);
	if (c == 'P')
		return (ft_player_spawn(i, y, ptr));
	return (ptr->img_0_ptr);
}

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
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_EO_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_CC_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_CO_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PD_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PU_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PL_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PR_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PUC_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PLC_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PRC_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_PDC_ptr);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	mlx_destroy_display(ptr->mlx_ptr);
	free(ptr->mlx_ptr);
	exit(0);
}
