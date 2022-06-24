/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:14:36 by tlarraze          #+#    #+#             */
/*   Updated: 2022/06/24 15:26:57 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "libft.h"

typedef	struct	s_ptr
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_0_ptr;
	void	*img_1_ptr;
	void	*img_EC_ptr;
	void	*img_EO_ptr;
	void	*img_CC_ptr;
	void	*img_CO_ptr;
	void	*img_PU_ptr;
	void	*img_PD_ptr;
	void	*img_PL_ptr;
	void	*img_PR_ptr;
	void	*img_PDC_ptr;
	void	*img_PLC_ptr;
	void	*img_PRC_ptr;
	void	*img_PUC_ptr;
	void	*player;
	char	**map;
	int		h;
	int		v;
	int		ph;
	int		pv;
	int		eh;
	int		ev;
	int		end_allow;
	int		end;
}	s_ptr;

int		use_key(int key, s_ptr *ptr);
int		ft_window_size(char *map, int side);
void	ft_background(s_ptr ptr, int h, int v);
void	ft_wall(char *map, s_ptr ptr, int size);
int		ft_search(char c, char *map);
char	**ft_make_tab(char **tab, char *map);
void	ft_make_map(s_ptr *ptr);
void	*ft_find_img(char c, s_ptr *ptr, int i, int y, int t);
void	ft_load_img(s_ptr *ptr, int size);
void	ft_free(s_ptr *ptr);
char	ft_check_block(s_ptr *ptr, int h, int v);
int		ft_move(s_ptr *ptr, int h, int v, char t);
void	ft_last_move(s_ptr *ptr, int h, int v);
void	ft_check_chest(s_ptr *ptr);
void    *ft_move_img(s_ptr *ptr, int h, int v, char c);