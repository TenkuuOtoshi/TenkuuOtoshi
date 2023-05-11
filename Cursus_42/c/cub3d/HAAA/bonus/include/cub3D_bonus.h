#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# define WIN_W 1920
# define WIN_H 1080

# define MINMAP_W 320 /*WIN_W / 6*/
# define MINMAP_H 320 /*WIN_W / 6*/

# define MINMAP_R 160 /*MINMAP_W / 2*/

# define MINMAP_PLAYER_R 4 /*WIN_W / 480*/

# define MINMAP_WALL_COLOUR 0x808080 /*gray*/
# define MINMAP_GROUND_COLOUR 0xc0c0c0 /*silver*/
# define MINMAP_ZOOM 5 /*Number of tiles that can be seen around the player's position*/

# define GREEN_SCREEN 0x3EFF00



# define PINK 0xFF00FF /*A SUPPRIMER*/
# define ORANGE 0xFFa500 /*A SUPPRIMER*/
# define BLACK 0x000000 /*A SUPPRIMER*/
# define MINMAP_VOID_COLOUR 0x008080 /*A SUPPRIMER*/
# define PURPLE 0x800080

# define MINMAP_LEN_RAY 15 /*A SUPPRIMER*/
# define PLANE 0.90
# define ROTSPEED 1
# define MOVESPEED 5

# define BRED "\e[1;31m"
# define RESET "\e[0m"
# define NB_TEXTURES 6
# define ALLOWED_MAP_CHARSET "\n10NSEW "
# define FILE_EXT ".cub"

# include "libft.h"
# include "cub3D_structs_bonus.h"
# include <math.h>

# include <stdio.h> /*perror*/

# include "mlx.h"
# include "mlx_int.h"

int				launch_program(t_game_cub *game);
int				ft_close(t_game_cub *game);
void			free_game(t_game_cub *game);

/************/
/*	Parsing	*/
/************/

int				check_element_part(t_game_cub *game);
int				check_elements_validity(const char **textures);
int				check_file_validity(const char *file_path);
int				check_map_part(t_game_cub *game);

/************/
/*	INIT	*/
/************/

t_frame_cub		*init_frame(char *path, t_mlx_cub *mlx);
t_game_cub		*init_game(const char *file_path);
t_keys_cub		init_keys(void);
t_map_cub		*init_map(void);
char			**init_matrix(int size_y, int size_x);
t_img_cub		*init_minimap(t_mlx_cub *mlx);
//t_img_cub		*init_minimap_border(char *path, t_mlx_cub *mlx);
t_mlx_cub		*init_mlx(void);
t_player_cub	*init_player(void);
t_img_cub		*init_screen(t_mlx_cub *mlx);
t_textures_cub	*init_textures(void);
void	ft_init_value(t_game_cub *game);
void	ft_init_math_value(t_game_cub *game, t_math_cub *math);

/********************/
/*	PARSING_UTILS	*/
/********************/

int				are_boundaries_closed(const char **matrix, int size_y,
					int size_x);
int				close_file(int file_fd, const char *file_path);
int				fill_matrix_holes(char **matrix, int size_x);
void			free_temp_textures_arr(char **textures);
int				get_index_element(const char **splitted, t_keys_cub keys,
					const char *file_line);
char			*get_first_map_line(int file_fd);
char			*get_first_non_empty_line(int file_fd);
int				get_map_infos(const char *file_path, t_map_cub *map, t_game_cub *game);
int				get_player_pos(t_game_cub *game, const char **matrix);
int				is_file_finished(int file_fd);
int				is_line_empty(const char *str);
int				is_line_valid(const char **splitted, t_keys_cub keys,
					const char **textures, const char *file_line);
int				is_rgb_valid(const char *texture);
int				is_there_forbidden_char(const char *str,
					const char *allowed_charset);
int				open_o_rdonly(const char *file_path);
void			read_file_to_the_end(int file_fd, char *file_line);

/************/
/*	MINIMAP	*/
/************/

int				display_minimap(t_game_cub *game);

/****************/
/*	PRINTING	*/
/****************/

void	ft_print_everything(t_game_cub *game, t_math_cub *math);
void	ft_raycasting(t_game_cub *game, t_math_cub *math);
void	ft_draw_verline(int x, t_math_cub *math, t_game_cub *game);

/****************/
/*	MOVEMENT	*/
/****************/

int	use_key(int key, t_game_cub *game);
int	ft_check_move_up_x(t_game_cub *game, t_math_cub *math);
int	ft_check_move_up_y(t_game_cub *game, t_math_cub *math);
int	ft_check_move_down_x(t_game_cub *game, t_math_cub *math);
int	ft_check_move_down_y(t_game_cub *game, t_math_cub *math);
int	ft_check_move_left_x(t_game_cub *game, t_math_cub *math);
int	ft_check_move_left_y(t_game_cub *game, t_math_cub *math);
int	ft_check_move_right_x(t_game_cub *game, t_math_cub *math);
int	ft_check_move_right_y(t_game_cub *game, t_math_cub *math);
int	ft_check_next_move(t_game_cub *game, t_math_cub *math , int direction);
int	ft_move_cursor(t_game_cub *game);

/********************/
/*	MINIMAP_UTILS	*/
/********************/

int				convert_rgb_into_int(char **rgb);
int				get_matrix_coord_colour(t_game_cub *game, int pixel_x, int pixel_y);
int				get_pixel(t_img_cub *img, int x, int y);
void			my_mlx_pixel_put(t_img_cub *img, int x, int y, int colour);

#endif
