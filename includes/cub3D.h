/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:04:52 by afournie          #+#    #+#             */
/*   Updated: 2026/06/22 16:23:02 by afournie         ###   ########.fr       */
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
# define DOOR			'D'
# define WALL			'1'
# define EXIT			'E'

//	DOORS
# define OPEN			"open"
# define CLOSE			"close"
# define UNDEFINED		"undefined"
# define LDOOR_TEX		"./map/door_l.xpm"
# define RDOOR_TEX		"./map/door_r.xpm"

// FLOOR / CEIL
# define FLOOR_TEX		"./textures/colorstone.xpm"
# define CEILING_TEX	"./textures/mossy.xpm"

//	KEYS
# define W_KEY			119
# define A_KEY			97
# define S_KEY			115
# define D_KEY			100
# define E_KEY			101
# define SHIFT_KEY		65505
# define UP_KEY			65362
# define LEFT_KEY		65361
# define DOWN_KEY		65364
# define RIGHT_KEY		65363
# define ESC_KEY		0xFF1B

/********************************/
/*			ENUMERATIONS		*/
/********************************/
typedef enum e_door_state
{
	DOOR_OPEN,
	DOOR_CLOSE,
	DOOR_UNDEFINED
}	t_door_state;

/********************************/
/*			STRUCTURES			*/
/********************************/
typedef struct s_keys
{
	bool			w;
	bool			s;
	bool			a;
	bool			d;
	bool			left;
	bool			right;
	bool			shift;
}	t_keys;

typedef struct s_player
{
	int				radius;
	double			mov_speed;
	double			rot_speed;
	double			posx;
	double			posy;
	double			dirx;		// -1 N | 1 S | 0
	double			diry;		// -1 W | 1 E | 0
	double			planex;		// -0.66 W | 0.66 E | 0
	double			planey;		// -0.66 N | 0.66 S | 0
	double			raydir_x;
	double			raydir_y;
	double			camerax;	// Position camera
}	t_player;

typedef struct s_minimap
{
	int				width;
	int				height;
	int				cell_size;
	int				p_radius;
	double			p_posx;
	double			p_posy;
}	t_minimap;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_data;

typedef struct s_door
{
	t_door_state	state;
	int				nb_doors;
	int				map_x;
	int				map_y;
}	t_door;

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
	t_door			*doors;
}			t_map;

typedef struct s_ray
{
	double			camerax;
	double			dirx;
	double			diry;
	double			posx;
	double			posy;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
}	t_ray;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}	t_img;

typedef struct s_draw
{
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				y;
	int				color;
}	t_draw;

typedef struct s_tex_data
{
	t_img			tex;
	char			*tex_path;
	int				has_tex;
}	t_tex_data;

typedef struct s_textures
{
	int				ceiling_color;
	int				floor_color;
	int				has_ceiling;
	int				has_floor;
	int				has_door;

	t_tex_data		rdoor;
	t_tex_data		ldoor;
	t_tex_data		no;
	t_tex_data		so;
	t_tex_data		we;
	t_tex_data		ea;
	t_tex_data		ceiling;
	t_tex_data		floor;
}	t_textures;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	long			last_frame;
	bool			mouse_warping;
	int				tile_size;

	t_textures		tex;
	t_map			map;
	t_player		player;
	t_ray			ray;
	t_minimap		minimap;
	t_keys			keys;
	t_data			data;
}	t_game;

/********************************/
/*			PROTOTYPES			*/
/********************************/

//	graphics
//		graphics.c
void		init_textures(t_game *game);

//	parsing
//		colors_utils.c
void		check_split(char **split);
//		colors.c
bool		get_colors(t_textures *tex, char *line);
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
bool		get_map_info(t_game *game, t_map *map, char *map_path);
//		textures.c
bool		get_textures(t_textures *tex, char *line);
//		verify.c
bool		is_valid_texture_path(t_textures *tex);
bool		is_valid_texture(t_game *game);
bool		verify_all_data(t_map *map, t_textures *tex);

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
//		utils.c
double		get_perp_wall_dist(t_ray *ray);
t_img		*get_wall_texture(t_game *game, t_ray *ray);
int			get_texture_pixel(t_img *tex, int x, int y);
//		raycaster.c
void		raycast(t_game *game);
void		init_step(t_ray *ray);
void		dda_loop(t_map *map, t_ray *ray);

//	render
//		floorcasting.c
//void		floor_casting(t_game *g);
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
//		t_door.c
t_door		t_door_new(t_door_state state, int map_x, int map_y, int nb_doors);
void		t_door_fill(t_game *game, t_map *map);
t_door		*t_door_get(t_door *doors, int map_x, int map_y);
void		t_door_state_switch(t_door *door);
//		t_draw.c
void		t_draw_init(t_draw *d, double dist);
//		t_game.c
t_game		t_game_new(char *map_path);
//		t_img.c
t_img		t_img_new(void);
void		t_img_free(void *mlx, t_img *img);
//		t_keys.c
t_keys		t_keys_new(void);
//		t_map.c
t_map		t_map_new(t_game *game, char *map_path);
void		t_map_free(t_map *map);
//		t_minimap.c
t_minimap	t_minimap_new(t_map map, t_ray ray);
void		t_minimap_update(t_minimap *minimap, t_ray ray);
//		t_player.c
t_player	t_player_new(t_game game);
//		t_ray.c
t_ray		t_ray_new(void);
void		t_ray_update(t_game *game, t_ray *ray, int x);
//		t_tex_data.c
t_tex_data	t_tex_data_new(void);
void		t_tex_data_free(void *mlx, t_tex_data *tex_data);
//		t_textures.c
t_textures	t_textures_new(void);
void		t_textures_free(void *mlx, t_textures *tex);

//	utils
//		mlx_utils.c
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);
//		utils.c
void		validation_failed_exit(t_game *game, t_map *map);
int			clean_exit(t_game *game);
long		get_time_us(void);
bool		is_valid_case(t_door *door, char c);

#endif
