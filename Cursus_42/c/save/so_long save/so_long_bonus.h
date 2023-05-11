/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:22:30 by tlarraze          #+#    #+#             */
/*   Updated: 2022/07/28 13:24:13 by tlarraze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	void	*img_eo0_ptr;
	void	*img_eo1_ptr;
	void	*img_cc_ptr;
	void	*img_cos0_ptr;
	void	*img_pu_ptr;
	void	*img_pd_ptr;
	void	*img_pds1_ptr;
	void	*img_pds2_ptr;
	void	*img_pds3_ptr;
	void	*img_pds4_ptr;
	void	*img_pds5_ptr;
	void	*img_pdcs1_ptr;
	void	*img_pdcs2_ptr;
	void	*img_pdcs3_ptr;
	void	*img_pdcs4_ptr;
	void	*img_pdcs5_ptr;
	void	*img_prs1_ptr;
	void	*img_prs2_ptr;
	void	*img_prs3_ptr;
	void	*img_prs4_ptr;
	void	*img_prs5_ptr;
	void	*img_prcs1_ptr;
	void	*img_prcs2_ptr;
	void	*img_prcs3_ptr;
	void	*img_prcs4_ptr;
	void	*img_prcs5_ptr;
	void	*img_pls1_ptr;
	void	*img_pls2_ptr;
	void	*img_pls3_ptr;
	void	*img_pls4_ptr;
	void	*img_pls5_ptr;
	void	*img_plcs1_ptr;
	void	*img_plcs2_ptr;
	void	*img_plcs3_ptr;
	void	*img_plcs4_ptr;
	void	*img_plcs5_ptr;
	void	*img_pus1_ptr;
	void	*img_pus2_ptr;
	void	*img_pus3_ptr;
	void	*img_pus4_ptr;
	void	*img_pus5_ptr;
	void	*img_pucs1_ptr;
	void	*img_pucs2_ptr;
	void	*img_pucs3_ptr;
	void	*img_pucs4_ptr;
	void	*img_pucs5_ptr;
	void	*img_pl_ptr;
	void	*img_pr_ptr;
	void	*img_pdc_ptr;
	void	*img_plc_ptr;
	void	*img_prc_ptr;
	void	*img_puc_ptr;
	void	*img_n0_ptr;
	void	*img_n1_ptr;
	void	*img_n2_ptr;
	void	*img_n3_ptr;
	void	*img_n4_ptr;
	void	*img_n5_ptr;
	void	*img_n6_ptr;
	void	*img_n7_ptr;
	void	*img_n8_ptr;
	void	*img_n9_ptr;
	void	*img_cos1_ptr;
	void	*img_cos2_ptr;
	void	*img_cos3_ptr;
	void	*img_m_ptr;
	void	*img_m1_ptr;
	void	*img_m2_ptr;
	void	*img_gm_ptr;
	void	*img_dark_ptr;
	void	*img_win_ptr;
	void	*player;
	char	**map;
	char	p_side;
	int		player_state;
	int		chest_state;
	int		exit_state;
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
	int		sprite_speed;
	int		player_sprite_speed;
	int		monster_sprite_speed;
	int		monster_state;
	int		monster_move_speed;
	int		monster_side;
	int		death;
	char	*map_name;
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
void	ft_load_img2(t_ptr *ptr, int size);
void	ft_load_img3(t_ptr *ptr, int size);
void	ft_load_img4(t_ptr *ptr, int size);
void	ft_load_img5(t_ptr *ptr, int size);
void	ft_load_img6(t_ptr *ptr, int size);
void	ft_load_img7(t_ptr *ptr, int size);
void	ft_free(t_ptr *ptr);
void	ft_free2(t_ptr *ptr);
void	ft_free3(t_ptr *ptr);
void	ft_free4(t_ptr *ptr);
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
void	*ft_player_spawn(int i, int y, t_ptr *ptr);
char	**ft_fill_tab(int fd, char *str, size_t size, t_ptr *ptr);
int		ft_window_side_v(int pixel, int side, int fd, char *str);
void	ft_write_moves(t_ptr *ptr);
void	ft_write_moves2(t_ptr *ptr);
void	*ft_find_numbers(t_ptr *ptr, int nb);
int		ft_chest_sprite(t_ptr *ptr);
void	ft_put_sprite(t_ptr *ptr, int y, int i);
int		ft_exit_sprite(t_ptr *ptr);
void	ft_init(t_ptr *ptr);
void	ft_player_sprite(t_ptr *ptr);
void	ft_player_down_idle(t_ptr *ptr);
void	ft_player_down_idle_chest(t_ptr *ptr);
void	ft_player_left_idle(t_ptr *ptr);
void	ft_player_left_idle_chest(t_ptr *ptr);
void	ft_player_right_idle(t_ptr *ptr);
void	ft_player_right_idle_chest(t_ptr *ptr);
void	ft_player_up_idle_chest(t_ptr *ptr);
void	ft_player_up_idle(t_ptr *ptr);
void	ft_monster_sprite(t_ptr *ptr, int y, int i);
void	ft_check_death(t_ptr *ptr);
void	ft_restart_state_speed(t_ptr *ptr);
void	ft_allow_end(t_ptr *ptr, int i, int y);
void	ft_monster(t_ptr *ptr);
int		ft_monster_move(t_ptr *ptr, int i, int y);
int		ft_assign_side(t_ptr *ptr, int i, int y);
void	ft_monster_move_left(t_ptr *ptr, int i, int y);
void	ft_monster_move_right(t_ptr *ptr, int i, int y);
void	ft_bravo_six_going_dark(t_ptr *ptr);
size_t	ft_string_size(t_ptr *ptr);

#endif