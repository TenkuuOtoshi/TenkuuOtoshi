/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_moves_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:45:40 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/11 15:23:52 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_write_moves(t_ptr *ptr)
{
	if (ptr->moves <= 9)
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ft_find_numbers(ptr, ptr->moves), 0, 0);
	if (ptr->moves <= 99 && ptr->moves >= 10)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ft_find_numbers(ptr, ptr->moves % 10), 48, 0);
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ft_find_numbers(ptr, ptr->moves / 10), 0, 0);
	}
	if (ptr->moves <= 999 && ptr->moves >= 100)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ft_find_numbers(ptr, ptr->moves % 10), 96, 0);
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ft_find_numbers(ptr, ptr->moves / 100), 0, 0);
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ft_find_numbers(ptr, ptr->moves / 10 % 10), 48, 0);
	}
	if (ptr->moves > 999)
		ft_write_moves2(ptr);
}

void	ft_write_moves2(t_ptr *ptr)
{
	if (ptr->moves <= 9999 && ptr->moves >= 1000)
	{
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ft_find_numbers(ptr, ptr->moves % 10), 144, 0);
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ft_find_numbers(ptr, ptr->moves / 1000), 0, 0);
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ft_find_numbers(ptr, ptr->moves / 10 % 10), 96, 0);
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
			ft_find_numbers(ptr, ptr->moves / 100 % 10), 48, 0);
	}
}

void	*ft_find_numbers(t_ptr *ptr, int nb)
{
	if (nb == 0)
		return (ptr->img_n0_ptr);
	if (nb == 1)
		return (ptr->img_n1_ptr);
	if (nb == 2)
		return (ptr->img_n2_ptr);
	if (nb == 3)
		return (ptr->img_n3_ptr);
	if (nb == 4)
		return (ptr->img_n4_ptr);
	if (nb == 5)
		return (ptr->img_n5_ptr);
	if (nb == 6)
		return (ptr->img_n6_ptr);
	if (nb == 7)
		return (ptr->img_n7_ptr);
	if (nb == 8)
		return (ptr->img_n8_ptr);
	return (ptr->img_n9_ptr);
}
