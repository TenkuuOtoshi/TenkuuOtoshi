/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:03:03 by tlarraze          #+#    #+#             */
/*   Updated: 2022/06/24 15:58:24 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(s_ptr *ptr)
{
	int		i;

	i = 0;
	while (ptr->map[i] != NULL)
	{
		free(ptr->map[i]);
		i++;
	}
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
}

char	ft_check_block(s_ptr *ptr, int h, int v)
{
	int	tmpv;
	int	tmph;

	tmph = h / 48;
	tmpv = v / 48;
	if (ptr->map[tmpv][tmph] == 'C')
	{
		ptr->map[tmpv][tmph] = 'O';
	}
	return (ptr->map[tmpv][tmph]);
}

int	ft_move(s_ptr *ptr, int h, int v, char c)
{
	if (ft_check_block(ptr, h, v) != '1' && (ft_check_block(ptr, h, v) != 'E' || ptr->end != 0))
	{
		mlx_put_image_to_window(ptr->mlx_ptr,ptr->win_ptr, ft_move_img(ptr, h, v, c), h, v);
		ptr->ph = h;
		ptr->pv = v;
		ft_check_chest(ptr);
		return (1);
	}
	ft_check_chest(ptr);
	return (0);
}

void	ft_last_move(s_ptr *ptr, int h, int v)
{
	if (ft_check_block(ptr, h, v) == 'P')
	{
		ptr->map[h / 48][v / 48] = 'O';
		printf("%c", ptr->map[h/48][v/48]);
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_0_ptr, h, v);
	}
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,ft_find_img(ft_check_block(ptr, h, v), ptr, h / 48, 
			v / 48, 1), h, v);
}

void	ft_check_chest(s_ptr *ptr)
{
	int i;
	int y;
	int	c;

	i = 0;
	y = 0;
	c = 0;
	while (ptr->map[i] != NULL)
	{
		while (ptr->map[i][y] != '\0')
		{
			if (ptr->map[i][y] == 'C')
				c++;
			y++;
		}
		y = 0;
		i++;
	}
	if (c == 0)
	{
		ptr->end = 1;
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_EO_ptr, ptr->eh, ptr->ev);
	}
}