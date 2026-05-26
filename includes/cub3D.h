/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:04:52 by afournie          #+#    #+#             */
/*   Updated: 2026/05/26 16:49:23 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/********************************/
/*			INCLUDES			*/
/********************************/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include "libft.h"
# include "mlx.h"

/********************************/
/*			CONSTANTES			*/
/********************************/
//	COLORS
# define WHITE			0x00FFFFFF
# define BLACK			0x00000000
# define GREY			0x009E9E9E
# define SKY_BLUE		0x0082C8E5
# define RED			0x00FF0000
# define WOOD_BROWN		0x009d7153

//	MATH
# ifndef M_PI
#  define M_PI			3.14159265358979323846
# endif

//	GAME
# define WIN_HEIGHT		900
# define WIN_WIDTH		1512
# define FPS			60

//	PLAYER
# define FOV			100
# define ROT_SPEED		4.0
# define MOV_SPEED		200.0
# define SPEED_MULT		2

//	MINIMAP
# define ATH_SIZE		200
# define RAYCAST_RANGE	100

//	MAP
# define WEST_SPAWN		'W'
# define EST_SPAWN		'E'
# define NORTH_SPAWN	'N'
# define SOUTH_SPAWN	'S'
# define FLOOR			'0'
# define WALL			'1'
# define EXIT			'E'

//	KEYS
# define W_KEY			119
# define A_KEY			97
# define S_KEY			115
# define D_KEY			100
# define SHIFT_KEY		65505
# define UP_KEY			65362
# define LEFT_KEY		65361
# define DOWN_KEY		65364
# define RIGHT_KEY		65363
# define ESC_KEY		0xFF1B

/********************************/
/*			STRUCTURES			*/
/********************************/
typedef struct s_keys
{
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	left;
	bool	right;
	bool	shift;
}	t_keys;

typedef struct s_player
{
	int		radius;
	double	mov_speed;
	double	rot_speed;
	double	posx;
	double	posy;
	double	dirx;		// -1 N | 1 S | 0
	double	diry;		// -1 W | 1 E | 0
	double	planex;		// -0.66 W | 0.66 E | 0
	double	planey;		// -0.66 N | 0.66 S | 0
	double	raydir_x;
	double	raydir_y;
	double	camerax;	// Position camera
}	t_player;

typedef struct s_minimap
{
	int		width;
	int		height;
	int		cell_size;
	int		p_radius;
	double	p_posx;
	double	p_posy;
}	t_minimap;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;

	char	*no_txt;
	char	*so_txt;
	char	*we_txt;
	char	*ea_txt;
	int		floor_color;
	int		ceiling_color;

	int		has_no;
	int		has_so;
	int		has_we;
	int		has_ea;
	int		has_floor;
	int		has_ceiling;
}			t_map;

typedef struct s_ray
{
	double	camerax;
	double	dirx;
	double	diry;
	double	posx;
	double	posy;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	long		last_frame;
	bool		mouse_warping;
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_minimap	minimap;
	t_keys		keys;
	t_data		data;
}	t_game;

/********************************/
/*			PROTOTYPES			*/
/********************************/

//	!!! DEBUG !!!
char		**debug_map(void);

//	parsing
//		colors.c
bool		get_colors(t_map *map, char *line);
//		flood_fill.c
bool		flood_fill(char **map, int y, int x);
//		map_utils.c
char		**copy_map(char **map);
void		free_map(char **map);
bool		find_player(char **map, int *py, int *px);
//		map.c
bool		is_player(char c);
bool		check_map(char **map);
//		parsing_utils.c
char		*expand_tabs(char *line);
//		parsing.h
bool		get_map_info(t_map *map, char *map_path);
//		textures.c
bool		get_textures(t_map *map, char *line);
//		verify.c
bool		is_valid_texture_path(t_game *game);
bool		is_valid_texture(t_game *game);
bool		verify_all_data(t_map *map);

//	player
//		camera.c
void		rotate_player(t_player *player, double angle);
//		player_action.c
int			key_press(int key, t_game *game);
int			key_release(int key, t_game *game);
//		mouse_action.c
int			mouse_click(int button, int x, int y, t_game *game);
int			mouse_movement(int x, int y, t_game *game);
//		player.c
void		update_player(t_game *game);

//	raycast
//		raycaster.c
void		raycast(t_game *game);
void		init_step(t_ray *ray);
void		dda_loop(t_game *game, t_ray *ray);

//	render
//		minimap_draw.c
void		draw_player(t_game *game, int cx, int cy, int color);
void		draw_raycast(t_game *game);
//		minimap.c
void		minimap(t_game *game, int ground_c, int wall_c, int player_c);
//		game.c
int			render_next_frame(t_game *game);

//	structures
//		t_data.c
t_data		t_data_new(void	*mlx_ptr);
//		t_game.c
t_game		t_game_new(char *map_path);
//		t_keys.c
t_keys		t_keys_new(void);
//		t_map.c
t_map		t_map_new(char *map_path);
//		t_minimap.c
t_minimap	t_minimap_new(t_map map, t_ray ray);
void		t_minimap_update(t_minimap *minimap, t_ray ray);
//		t_player.c
t_player	t_player_new(void);
//		t_ray.c
t_ray		t_ray_new(void);
void		t_ray_update(t_game *game, t_ray *ray, int x);

//	utils
//		mlx_utils.c
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);
//		utils.c
int			clean_exit(t_game *game);
long		get_time_us(void);

#endif
