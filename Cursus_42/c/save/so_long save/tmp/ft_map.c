/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:56:55 by tlarraze          #+#    #+#             */
/*   Updated: 2022/06/20 13:34:50 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	ft_background(s_ptr ptr, int h, int v)
{
	int tmph;
	int	size;

	tmph = 0;
	size = 48;

	while (v >= 0)
	{
		while (tmph != h)
		{
			ptr.img_ptr = mlx_xpm_file_to_image(ptr.mlx_ptr, "0.xpm", &size, &size);
			mlx_put_image_to_window(ptr.mlx_ptr, ptr.win_ptr, ptr.img_ptr, tmph, v);
			tmph = tmph + 48;
			(void)ptr;
			(void)v;
		}
		v = v - 48;
		tmph = 0;
		ptr.img_ptr = mlx_xpm_file_to_image(ptr.mlx_ptr, "0.xpm", &size, &size);
		mlx_put_image_to_window(ptr.mlx_ptr, ptr.win_ptr, ptr.img_ptr, tmph, v);

	}
	//ptr.img_ptr = mlx_xpm_file_to_image(ptr.mlx_ptr, "0.xpm", &x, &y);

}

void	ft_wall(char *map, s_ptr ptr, int size)
{
	int		i;
	int		h;
	int		v;
	int		fd;
	char	*str;

	v = 0;
	h = 0;
	i = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		while (str[i] != '\0')
		{
			if (str[i] == '1')
			{
			ptr.img_ptr = mlx_xpm_file_to_image(ptr.mlx_ptr, "1.1.xpm", &size, &size);
			mlx_put_image_to_window(ptr.mlx_ptr, ptr.win_ptr, ptr.img_ptr, h, v);
			}
		i++;
		h = h + 48;
		}
		printf("%s", str);
		str = get_next_line(fd);
		h = 0;
		v = v + 48;
		i = 0;
	}
	free(str);
	close(fd);
}

s_chest	**ft_spawn_chest(char *map, int size, s_ptr ptr, s_chest **chest)
{
	int		i;
	int		y;
	int		h;
	int		v;
	int		fd;
	char	*str;

	y = 0;
	v = 0;
	h = 0;
	i = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		while (str[i] != '\0')
		{
			if (str[i] == 'C')
			{
			chest[y] = malloc(1 * sizeof(s_chest));
			chest[y]->img_ptr = mlx_xpm_file_to_image(ptr.mlx_ptr, "CC.xpm", &size, &size);
			mlx_put_image_to_window(ptr.mlx_ptr, ptr.win_ptr, chest[y]->img_ptr, h, v);
			chest[y]->h = h;
			chest[y]->v = v;
			chest[y]->status = 'c';
			y++;
			}
		i++;
		h = h + 48;
		}
		str = get_next_line(fd);
		h = 0;
		v = v + 48;
		i = 0;
	}
	chest[y] = '\0';
	free(str);
	close(fd);
	return (chest);
}
*/
int	ft_search(char c, char *map)
{
	int		i;
	int		fd;
	int		count;
	char	*str;

	i = 0;
	count = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		while (str[i] != '\0')
		{
			if (str[i] == c)
				count++;
			i++;
		}
		i = 0;
		str = get_next_line(fd);
	}
	close(fd);
	return (count);
}
/*
s_chest	ft_player(s_chest player, s_ptr ptr, char *map, int size)
{
	int		i;
	int		v;
	int		h;
	int 	fd;
	char	*str;

	i = 0;
	v = 0;
	h = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		while (str[i] != '\0')
		{
			if (str[i] == 'P')
			{
				player.img_ptr = mlx_xpm_file_to_image(ptr.mlx_ptr, "P.xpm", &size, &size);
				mlx_put_image_to_window(ptr.mlx_ptr, ptr.win_ptr, player.img_ptr, h, v);
				player.h = h;
				player.v = v;
				free(str);
				close(fd);
				return (player);
			}
			i++;
			h = h + 48;
		}
		str = get_next_line(fd);
		h = 0;
		v = v + 48;
		i = 0;
	}
	free(str);
	close(fd);
	return (player);
}
*/