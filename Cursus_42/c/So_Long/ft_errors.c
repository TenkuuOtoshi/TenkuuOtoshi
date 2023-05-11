/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:05:23 by tlarraze          #+#    #+#             */
/*   Updated: 2022/08/09 10:09:38 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		ft_putstr_fd("Error\n", 2);
	if (c == 0)
		ft_putstr_fd("Need 1 item on the map (C)\n", 2);
	if (p == 0)
		ft_putstr_fd("Need 1 player on the map (P)\n", 2);
	if (ft_bad_symbole(ptr) == 1)
		ft_putstr_fd("Unknown symbole found (?)\n", 2);
	if (p > 1)
		ft_putstr_fd("You can only have 1 player on the map (P)\n", 2);
	if (e == 0)
		ft_putstr_fd("Need 1 exit on the map (E)\n", 2);
	if (e > 1)
		ft_putstr_fd("You can only have 1 exit on the map (E)\n", 2);
	if (ft_check_walls(ptr) == 1)
		ft_putstr_fd("Map borders can only be walls (1)\n", 2);
	if (ptr->sidecheck > 0)
		ft_putstr_fd("Map must be rectangular (1)\n", 2);
	if (ft_check_empty(c, p, e, ptr) == 1 || ptr->sidecheck > 0
		|| ft_bad_symbole(ptr) == 1)
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

void	ft_check_empty_map(char *map)
{
	int		fd;
	char	*str;

	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	if (str == NULL)
	{
		ft_putstr_fd("Error\nMap given is empty/null\n", 2);
		free(str);
		exit(0);
	}
	if (str != NULL && ft_so_long_strlen(str) <= 2)
	{
		ft_putstr_fd("Error\nMap given is empty/null\n", 2);
		free(str);
		exit(0);
	}
	free(str);
}
