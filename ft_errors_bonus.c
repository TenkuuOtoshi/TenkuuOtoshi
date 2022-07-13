/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:05:23 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/11 15:12:24 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_map_error(t_ptr *ptr, int i, int y)
{
	int	c;
	int	p;
	int	e;

	c = 0;
	p = 0;
	e = 0;
	while (ptr->map[i] != NULL)
	{
		while (ptr->map[i][y] != '\0')
		{
			if (ptr->map[i][y] == 'C')
				c++;
			if (ptr->map[i][y] == 'P')
				p++;
			if (ptr->map[i][y] == 'E')
				e++;
			y++;
		}
		y = 0;
		i++;
	}
	ft_put_error(c, p, e, ptr);
}

void	ft_put_error(int c, int p, int e, t_ptr *ptr)
{
	if (ft_check_empty(c, p, e, ptr) == 1 || ft_check_walls(ptr) == 1)
		ft_putstr("Error\n");
	if (c == 0)
		ft_putstr("Need 1 item on the map (C)\n");
	if (p == 0)
		ft_putstr("Need 1 player on the map (P)\n");
	if (p > 1)
		ft_putstr("You can only have 1 player on the map (P)\n");
	if (e == 0)
		ft_putstr("Need 1 exit on the map (E)\n");
	if (e > 1)
		ft_putstr("You can only have 1 exit on the map (E)\n");
	if (ft_check_walls(ptr) == 1)
		ft_putstr("Map borders can only be walls (1)\n");
	if (ptr->sidecheck > 0)
		ft_putstr("Map must be rectangular (1)\n");
	if (ft_check_empty(c, p, e, ptr) == 1 || ptr->sidecheck > 0)
		ft_free(ptr);
}

int	ft_check_walls(t_ptr *ptr)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (y <= ptr->y)
	{
		while (ptr->map[y][i] != '\0')
		{
			if ((y == 0 && ptr->map[y][i] != '1') || ptr->map[y][0] != '1')
				return (1);
			if (ptr->map[y][i + 1] == '\0' && ptr->map[y][i] != '1')
				return (1);
			i++;
		}
		i = 0;
		y++;
	}
	while (ptr->map[ptr->y][i] != '\0')
	{
		if (ptr->map[ptr->y][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_so_long_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}
