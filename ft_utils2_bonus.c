/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:40:24 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/13 13:28:59 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_empty(int c, int p, int e, t_ptr *ptr)
{
	if (c == 0 || p == 0 || p > 1 || e == 0 || e > 1
		|| ft_check_walls(ptr) == 1)
		return (1);
	return (0);
}

void	*ft_player_spawn(int i, int y, t_ptr *ptr)
{
	ptr->map[i][y] = '0';
	ptr->h = y * 48;
	ptr->v = i * 48;
	return (ptr->img_pd_ptr);
}

char	**ft_fill_tab(int fd, char *str, size_t size, t_ptr *ptr)
{
	int	y;

	y = 0;
	while (str != NULL)
	{
		ft_strlcpy(ptr->map[y], str, size + 1);
		ptr->map[y][size] = '\0';
		if (ft_so_long_strlen(str) != size)
			ptr->sidecheck = 1;
		free(str);
		str = get_next_line(fd);
		y++;
	}
	free(str);
	return (ptr->map);
}

int	ft_window_side_v(int pixel, int side, int fd, char *str)
{
	if (side == 'v')
	{
		str = get_next_line(fd);
		while (str != NULL)
		{
			free(str);
			pixel++;
			str = get_next_line(fd);
		}
	}
	free(str);
	close(fd);
	return (pixel * 48);
}

int	ft_use_key2(int key, t_ptr *ptr)
{
	if ((key == XK_d || key == XK_Right) && ptr->death == 0)
	{
		if (ft_move(ptr, ptr->ph + 48, ptr->pv, 'd') == 1)
			ft_last_move(ptr, ptr->ph - 48, ptr->pv);
	}
	if ((key == XK_s || key == XK_Down) && ptr->death == 0)
	{
		if (ft_move(ptr, ptr->ph, ptr->pv + 48, 's') == 1)
			ft_last_move(ptr, ptr->ph, ptr->pv - 48);
	}
	if (ptr->ph == ptr->eh && ptr->pv == ptr->ev && ptr->end == 1)
	{
		ptr->death = 1;
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_win_ptr,
			(ft_strlen(ptr->map[0])) * 48 / 2 - 48,
			(ft_window_size(ptr->map_name, 'v', ptr) / 2) - 96);
	}
	return (0);
}
