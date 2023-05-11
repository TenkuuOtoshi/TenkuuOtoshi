/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:56:55 by tlarraze          #+#    #+#             */
/*   Updated: 2022/08/02 14:59:48 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_make_tab(char **tab, char *map, t_ptr *ptr)
{
	size_t		y;
	size_t		s;
	int			fd;
	char		*str;

	y = 0;
	ptr->sidecheck = 0;
	s = ft_string_size(map);
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	tab = (char **)calloc((ft_window_size(map, 'v', ptr) / 48) + 1,
			sizeof(char *));
	tab[ft_window_size(map, 'v', ptr) / 48] = NULL;
	while (y < (unsigned int)ft_window_size(map, 'v', ptr) / 48)
	{
		tab[y] = (char *)calloc(s + 1, sizeof(char));
		y++;
	}
	ptr->map = tab;
	ptr->y = y - 1;
	tab = ft_fill_tab(fd, str, s, ptr);
	close(fd);
	return (tab);
}

void	ft_make_map(t_ptr *ptr, int h, int v)
{
	unsigned int	i;
	unsigned int	y;

	i = 0;
	y = 0;
	ft_check_map_error(ptr, i, y);
	while (ptr->map[i] != NULL)
	{
		while (ptr->map[i][y] != '\0')
		{
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
				ft_find_img(ptr->map[i][y], ptr, i, y), h, v);
			h += 48;
			y++;
		}
		v += 48;
		y = 0;
		h = 0;
		i++;
	}
	ptr->ph = ptr->h;
	ptr->pv = ptr->v;
}

size_t	ft_string_size(char *map)
{
	size_t	s;
	int		fd;
	char	*str;

	s = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		if (ft_so_long_strlen(str) > s)
			s = ft_so_long_strlen(str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (s);
}
