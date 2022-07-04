/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:56:55 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/04 14:39:43 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_make_tab(char **tab, char *map, s_ptr *ptr)
{
	size_t		y;
	size_t		s;
	int			fd;
	char		*str;
	size_t		size;

	y = 0;
	ptr->sidecheck = 0;
	s = ft_window_size(map, 'h', ptr) / 48;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	size = ft_so_long_strlen(str);
	tab = (char **)calloc(size + 1, sizeof(char *));
	tab[ft_so_long_strlen(str)] = NULL;
	while (y < ft_so_long_strlen(str))
	{
		tab[y] = (char *)calloc(s + 2, sizeof(char));
		y++;
	}
	ptr->map = tab;
	tab = ft_fill_tab(fd, str, size, ptr);
	ptr->y = y - 1;
	close(fd);
	return (tab);
}

void	ft_make_map(s_ptr *ptr, int h, int v)
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
