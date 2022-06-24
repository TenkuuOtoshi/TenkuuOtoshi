/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:50:18 by tlarraze          #+#    #+#             */
/*   Updated: 2022/06/09 15:57:29 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//g ft_so_long.c -L. -lft -I. -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
// g t.c -L. -lft -I Update/Libft

int	use_key(int key, void *param)
{
	write(1, &key, 1);
	(void)param;
	if (key == XK_Escape)
		exit(0);
	return (0);
}

int	main()
{
	s_ptr	ptr;
	int		x;
	int		y;
	int		i;
//bon il faut un gnl ligne part ligne pour mettre la map rien de dur 
	i = 0;
	ptr->*mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, 666, 666, "Test mlx 42 Reborn !");
	mlx_key_hook(ptr->win_ptr, use_key, 0);
	ptr->img_ptr = mlx_xpm_file_to_image(mlx_ptr, "t.xpm", &x, &y);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, i, i);
	mlx_loop(mlx_ptr);
	(void)img_ptr;
	(void)win_ptr;	
}
