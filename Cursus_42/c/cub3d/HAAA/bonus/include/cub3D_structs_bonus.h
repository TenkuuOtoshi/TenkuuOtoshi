#ifndef CUB3D_STRUCTS_BONUS_H
# define CUB3D_STRUCTS_BONUS_H

typedef enum s_enum_rgb_cub
{
	R,
	G,
	B,
}	t_enum_rgb_cub;

typedef enum s_enum_textures_cub
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
}	t_enum_textures_cub;

typedef struct s_keys_cub
{
	char	*keys[NB_TEXTURES];
}	t_keys_cub;

typedef struct s_math_cub
{
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineheight;
	int		draw_start;
	int		draw_end;
	int		movespeed;
	int		rotspeed;
	float	plane;
	float	p_x;
	float	p_y;
	float	angle;
	double	time;
	double	oldtime;
	double	sideDistX;
	double	sideDistY;
	double	cameraX;
	double	raydirX;
	double	raydirY;
	double	DirX;
	double	DirY;
	double	planeX;
	double	planeY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
}	t_math_cub;

typedef struct	s_img_cub
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img_cub;

/*typedef struct s_texture_cub
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_texture_cub;*/

typedef struct s_frame_cub
{
	void	*img;
	char	*addr;
	char	*path;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_frame_cub;

typedef struct s_textures_cub
{
	t_frame_cub	**text_walls;
	char		**text_floor;
	char		**text_ceiling;
}	t_textures_cub;

typedef struct s_mlx_cub
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img_cub	*screen;
	t_img_cub	*minimap_border;
}	t_mlx_cub;

typedef struct s_player_cub
{
	float	pos_x;//suppimer NSEW de la matrice
	float	pos_y;
	//char facing == NSEW
}	t_player_cub;

typedef struct s_map_cub
{
	char	**matrix;
	int		size_y;
	int		size_x;
}	t_map_cub;

typedef struct s_game_cub
{
	t_map_cub		*map;
	t_player_cub	*player;
	t_mlx_cub		*mlx;
	t_textures_cub	*textures;
	const char		*file_path;
	float			matrix_ratio_y;
	float			matrix_ratio_x;
	float			minimap_ratio_y;
	float			minimap_ratio_x;
	int				mouse_x;
	int				mouse_y;
	t_math_cub		*math;
}	t_game_cub;

#endif
