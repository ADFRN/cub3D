/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:04:52 by afournie          #+#    #+#             */
/*   Updated: 2026/05/18 17:34:46 by afournie         ###   ########.fr       */
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
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
//	GAME
# define WIN_HEIGHT		900
# define WIN_WIDTH		1512
# define FPS			60
# define FRAME_TIME		(1000000 / FPS)	// En microsecondes
# define ROT_SPEED		4.0
# define MOV_SPEED		200.0
# define FOV			100
# define RENDER_DIST	300

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
}	t_keys;

typedef struct s_player
{
	int		radius;
	double	mov_speed;
	double	rot_speed;
	double	posX;
	double	posY;
	double	dirX;		// -1 N | 1 S | 0
	double	dirY;		// -1 W | 1 E | 0
	double	planeX;		// -0.66 W | 0.66 E | 0
	double	planeY;		// -0.66 N | 0.66 S | 0
	double	rayDirX;
	double	rayDirY;
	double	cameraX;	// Position camera
}	t_player;

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
	double	cameraX;
	double	dirX;
	double	dirY;
	double	posX;
	double	posY;
	double	deltaDistX;
	double	deltaDistY;
	double	sideDistX;
	double	sideDistY;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	long		last_frame;
	t_map		map;
	t_keys		keys;
	t_player	player;
	t_data		data;
}	t_game;

/********************************/
/*			PROTOTYPES			*/
/********************************/

//	!!! DEBUG !!!
char		**DEBUG_map();

// Parsing
bool	get_map_info(t_map *map, char *map_path);
bool	get_textures(t_map *map, char *line);
bool	get_colors(t_map *map, char *line);
bool	is_valid_texture(t_game *game);
bool	verify_all_data(t_map *map);
bool	check_map(char **map);


//	player.c
//		player_action.c
int			key_press(int key, t_game *game);
int			key_release(int key, t_game *game);
//		mouse_action.c
int			mouse_click(int button, int x, int y, void *param);
int			mouse_movement(int x, int y, void *param);
//		player.c
void		update_player(t_game *game);

//	raycast
//		raycaster.c
void		raycast(t_game *game);

//	render.c
//		draw.c
void		fill_image(t_game *game, int ground_color, int wall_color);
void		draw_circle(t_game *game, int cx, int cy, int radius, int color);
void		draw_raycast(t_game *game);
//		render.c
int			render_next_frame(t_game *game);

//	structures.c
//		t_data.c
t_data		t_data_new(void	*mlx_ptr);
//		t_game.c
t_game	t_game_new(char *map_path);
//		t_keys.c
t_keys		t_keys_new();
//		t_map.c
t_map		init_map(void);
t_map		t_map_new(char *map);
//		t_player.c
t_player	t_player_new();
//		t_ray.c
void		t_ray_init(t_game *game, t_ray *ray, int x);

//	utils.c
//		mlx_utils.c
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);
//		utils.c
int			clean_exit(t_game *game);
long		get_time_us(void);

#endif
