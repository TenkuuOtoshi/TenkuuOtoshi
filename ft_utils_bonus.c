/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:03:03 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/11 16:39:57 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	ft_check_block(t_ptr *ptr, int h, int v)
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

int	ft_move(t_ptr *ptr, int h, int v, char c)
{
	ptr->p_side = c;
	if (ft_check_block(ptr, h, v) != '1' && (ft_check_block(ptr, h, v)
			!= 'E' || ptr->end != 0) && ptr->death == 0)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ft_move_img(ptr, h, v, c), h, v);
		ptr->ph = h;
		ptr->pv = v;
		ptr->moves += 1;
		ft_write_moves(ptr);
		ft_check_chest(ptr);
		ft_check_death(ptr);
		return (1);
	}
	ft_check_chest(ptr);
	return (0);
}

void	ft_last_move(t_ptr *ptr, int h, int v)
{
	if (ft_check_block(ptr, h, v) == 'P' && ptr->death == 0)
	{
		ptr->map[h / 48][v / 48] = 'O';
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ptr->img_0_ptr, h, v);
	}
	if (ptr->death == 0)
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ft_find_img
			(ft_check_block(ptr, h, v), ptr, h / 48, v / 48), h, v);
}

void	ft_check_chest(t_ptr *ptr)
{
	int	i;
	int	y;
	int	c;

	i = 0;
	y = 0;
	c = 0;
	while (ptr->map[y] != NULL)
	{
		while (ptr->map[y][i] != '\0')
		{
			if (ptr->map[y][i] == 'C')
				c++;
			i++;
		}
		i = 0;
		y++;
	}
	if (c == 0)
	{
		ptr->end = 1;
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_eo0_ptr,
			ptr->eh, ptr->ev);
	}
}

int	ft_exit_sprite(t_ptr *ptr)
{
	if (ptr->exit_state == 0 && ptr->end == 1 && ptr->death == 0)
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_eo0_ptr,
			ptr->eh, ptr->ev);
	if (ptr->exit_state == 2 && ptr->end == 1 && ptr->death == 0)
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_eo1_ptr,
			ptr->eh, ptr->ev);
	if (ptr->exit_state == 2)
		ptr->exit_state = -1;
	ptr->exit_state++;
	return (0);
}
