/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:14:36 by tlarraze          #+#    #+#             */
/*   Updated: 2022/08/09 10:08:34 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <mlx_int.h>
# include <libft.h>

typedef struct t_ptr
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_0_ptr;
	void	*img_1_ptr;
	void	*img_ec_ptr;
	void	*img_eo1_ptr;
	void	*img_cc_ptr;
	void	*img_co_ptr;
	void	*img_pu_ptr;
	void	*img_pd_ptr;
	void	*img_pl_ptr;
	void	*img_pr_ptr;
	void	*img_pdc_ptr;
	void	*img_plc_ptr;
	void	*img_prc_ptr;
	void	*img_puc_ptr;
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
}	t_ptr;

int		use_key(int key, t_ptr *ptr);
int		ft_use_key2(int key, t_ptr *ptr);
size_t	ft_so_long_strlen(char *str);
int		ft_window_size(char *map, int side, t_ptr *ptr);
void	ft_background(t_ptr ptr, int h, int v);
void	ft_wall(char *map, t_ptr ptr, int size);
char	**ft_make_tab(char **tab, char *map, t_ptr *ptr);
void	ft_make_map(t_ptr *ptr, int h, int v);
void	*ft_find_img(char c, t_ptr *ptr, int i, int y);
void	ft_load_img(t_ptr *ptr, int size);
void	ft_free(t_ptr *ptr);
void	ft_free2(t_ptr *ptr);
char	ft_check_block(t_ptr *ptr, int h, int v);
int		ft_move(t_ptr *ptr, int h, int v, char t);
void	ft_last_move(t_ptr *ptr, int h, int v);
void	ft_check_chest(t_ptr *ptr);
void	*ft_move_img(t_ptr *ptr, int h, int v, char c);
void	ft_check_map_error(t_ptr *ptr, int i, int y);
void	ft_put_error(int c, int p, int e, t_ptr *ptr);
int		ft_check_walls(t_ptr *ptr);
int		ft_sidecheck(t_ptr *ptr, char *map);
int		ft_close(t_ptr *ptr);
int		ft_check_empty(int c, int p, int e, t_ptr *ptr);
void	ft_load_img2(t_ptr *ptr, int size);
void	*ft_player_spawn(int i, int y, t_ptr *ptr);
char	**ft_fill_tab(int fd, char *str, size_t size, t_ptr *ptr);
int		ft_window_side_v(int pixel, int side, int fd, char *str);
size_t	ft_string_size(char *map);
void	ft_check_empty_map(char *map);
int		ft_bad_symbole(t_ptr *ptr);

#endif
