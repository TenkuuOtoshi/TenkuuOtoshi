/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:14:36 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/04 14:35:05 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <mlx_int.h>
# include <libft.h>

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
	int		size;
	int		y;
	int		h;
	int		v;
	int		ph;
	int		pv;
	int		eh;
	int		ev;
	int		end_allow;
	int		end;
	int		moves;
	int		sidecheck;
	int		allow_map_change;
}	s_ptr;

int		use_key(int key, s_ptr *ptr);
int		ft_use_key2(int key, s_ptr *ptr);
size_t	ft_so_long_strlen(char *str);
int		ft_window_size(char *map, int side, s_ptr *ptr);
void	ft_background(s_ptr ptr, int h, int v);
void	ft_wall(char *map, s_ptr ptr, int size);
int		ft_search(char c, char *map);
char	**ft_make_tab(char **tab, char *map, s_ptr *ptr);
void	ft_make_map(s_ptr *ptr, int h, int v);
void	*ft_find_img(char c, s_ptr *ptr, int i, int y);
void	ft_load_img(s_ptr *ptr, int size);
void	ft_free(s_ptr *ptr);
char	ft_check_block(s_ptr *ptr, int h, int v);
int		ft_move(s_ptr *ptr, int h, int v, char t);
void	ft_last_move(s_ptr *ptr, int h, int v);
void	ft_check_chest(s_ptr *ptr);
void	*ft_move_img(s_ptr *ptr, int h, int v, char c);
void	ft_check_map_error(s_ptr *ptr, int i, int y);
void	ft_put_error(int c, int p, int e, s_ptr *ptr);
int		ft_check_walls(s_ptr *ptr);
int		ft_sidecheck(s_ptr *ptr, char *map);
int		ft_close(s_ptr *ptr);
int		ft_check_empty(int c, int p, int e, s_ptr *ptr);
void	ft_load_img2(s_ptr *ptr, int size);
void	*ft_player_spawn(int i, int y, s_ptr *ptr);
char	**ft_fill_tab(int fd, char *str, size_t size, s_ptr *ptr);
int		ft_window_side_v(int pixel, int side, int fd, char *str);

#endif