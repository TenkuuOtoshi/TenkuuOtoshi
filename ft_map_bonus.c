/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:56:55 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/13 13:33:12 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**ft_make_tab(char **tab, char *map, t_ptr *ptr)
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

void	ft_init(t_ptr *ptr)
{
	ptr->chest_state = 0;
	ptr->exit_state = 0;
	ptr->allow_map_change = 0;
	ptr->end = 0;
	ptr->end_allow = 0;
	ptr->sprite_speed = 0;
	ptr->player_state = 0;
	ptr->p_side = 's';
	ptr->player_sprite_speed = 0;
	ptr->monster_sprite_speed = 0;
	ptr->monster_state = 0;
	ptr->monster_move_speed = 0;
	ptr->monster_side = 0;
	ptr->death = 0;
}

void	ft_load_img6(t_ptr *ptr, int size)
{
	ptr->img_pus1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PUS1.xpm", &size, &size);
	ptr->img_pus2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PUS2.xpm", &size, &size);
	ptr->img_pus3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PUS3.xpm", &size, &size);
	ptr->img_pus4_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PUS4.xpm", &size, &size);
	ptr->img_pus5_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PUS5.xpm", &size, &size);
	ptr->img_pucs1_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PUCS1.xpm", &size, &size);
	ptr->img_pucs2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PUCS2.xpm", &size, &size);
	ptr->img_pucs3_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PUCS3.xpm", &size, &size);
	ptr->img_pucs4_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PUCS4.xpm", &size, &size);
	ptr->img_pucs5_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PUCS5.xpm", &size, &size);
	ptr->img_m_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/M.xpm", &size, &size);
	ft_load_img7(ptr, size);
}

void	ft_load_img7(t_ptr *ptr, int size)
{
	ptr->img_m2_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/M2.xpm", &size, &size);
	ptr->img_prcs4_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRCS4.xpm", &size, &size);
	ptr->img_prcs5_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/PRCS5.xpm", &size, &size);
	ptr->img_gm_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/GM.xpm", &size, &size);
	ptr->img_dark_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/DARK.xpm", &size, &size);
	ptr->img_win_ptr = mlx_xpm_file_to_image
		(ptr->mlx_ptr, "sprite/win.xpm", &size, &size);
}
