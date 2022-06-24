/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:56:55 by tlarraze          #+#    #+#             */
/*   Updated: 2022/06/24 16:20:59 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_make_tab(char **tab, char *map)
{
	size_t		y;
	int		fd;
	char	*str;

	y = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	tab = (char **)calloc(ft_strlen(str), sizeof(char *));
	tab[ft_strlen(str) - 1] = NULL;
	while (y != ft_strlen(str) - 1)
	{
		tab[y] = (char *)calloc(ft_window_size(map, 'v') / 48 + 1, sizeof(char));
		tab[ft_window_size(map, 'v') / 48 + 1] = '\0';
		y++;
	}
	y = 0;
	while (str != NULL)
	{
		ft_strlcpy(tab[y], str, ft_strlen(str));
		tab[y][ft_strlen(str) - 1] = '\0';
		printf("%s\n", tab[y]);
		free(str);
		str = get_next_line(fd);
		y++;
	}
	free(str);
	return (tab);
}

void	ft_make_map(s_ptr *ptr)
{
	unsigned int	i;
	unsigned int	y;
	int	h;
	int	v;

	h = 0;
	v = 0;
	i = 0;
	y = 0;
	while (ptr->map[i] != NULL)
	{
		while (ptr->map[i][y] != '\0')
		{
			mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr
			, ft_find_img(ptr->map[i][y], ptr, i, y, 0), h, v);
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

void	*ft_find_img(char c, s_ptr *ptr, int i, int y, int t)
{
	if (c == 'C' && t == 1)
	{
		ptr->map[y][i] = 'O';
		return (ptr->img_CO_ptr);
	}
	if (c == 'O')
		return (ptr->img_CO_ptr);
	if (c == '0')
		return (ptr->img_0_ptr);
	if (c == '1')
		return (ptr->img_1_ptr);
	if (c == 'E')
	{
		if (ptr->end_allow != 1	)
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
	{
		ptr->map[i][y] = '0';
		ptr->h = y * 48;
		ptr->v = i * 48;
		return (ptr->img_PD_ptr);
	}
	return (0);
}

void	ft_load_img(s_ptr *ptr, int size)
{
	ptr->img_0_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "0.xpm", &size, &size);
	ptr->img_1_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "1,1.xpm", &size, &size);
	ptr->img_EC_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "EC.xpm", &size, &size);
	ptr->img_EO_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "EO.xpm", &size, &size);
	ptr->img_CC_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "CC.xpm", &size, &size);
	ptr->img_CO_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "CO.xpm", &size, &size);
	ptr->img_PD_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "PD.xpm", &size, &size);
	ptr->img_PU_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "PU.xpm", &size, &size);
	ptr->img_PL_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "PL.xpm", &size, &size);
	ptr->img_PR_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "PR.xpm", &size, &size);
	ptr->img_PUC_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "PUC.xpm", &size, &size);
	ptr->img_PLC_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "PLC.xpm", &size, &size);
	ptr->img_PRC_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "PRC.xpm", &size, &size);
	ptr->img_PDC_ptr = mlx_xpm_file_to_image(ptr->mlx_ptr, "PDC.xpm", &size, &size);
}

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
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (count);
}
