/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:04:52 by afournie          #+#    #+#             */
/*   Updated: 2026/05/10 20:02:32 by ttiprez          ###   ########.fr       */
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
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include "libft.h"
# include "mlx.h"

/********************************/
/*			CONSTANTES			*/
/********************************/
# define FPS			60
# define FRAME_TIME		(1000000 / FPS)	// En microsecondes

# define WEST_SPAWN		'W'
# define EST_SPAWN		'E'
# define NORTH_SPAWN	'N'
# define SOUTH_SPAWN	'S'
# define FLOOR			'0'
# define WALL			'1'
# define EXIT			'E'

# define WIN_HEIGHT		500
# define WIN_WIDTH		500

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
	int	w;
	int	s;
	int	a;
	int	d;
}	t_keys;

typedef struct s_player
{
	int		radius;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
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
	int		map_width;
	int		map_height;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_keys		keys;
	t_player	player;
	t_data		data;
}	t_game;

/********************************/
/*			PROTOTYPES			*/
/********************************/

/*	!!! DEBUG.c !!!	*/
char		**DEBUG_map();

/*	player_interaction	*/
/*		player_action.c		*/
int			key_press(int key, t_game *game);
int			key_release(int key, t_game *game);
/*		mouse_action.c		*/
int			mouse_click(int button, int x, int y, void *param);
int			mouse_movement(int x, int y, void *param);

/*	structures	*/
/*		t_data.c	*/
t_data		t_data_new(void	*mlx_ptr);
/*		t_game.c	*/
t_game		t_game_new(char **map);
/*		t_keys.c	*/
t_keys		t_keys_new();
/*		t_map.c		*/
t_map		t_map_new(char **map);
/*		t_player.c	*/
t_player	t_player_new();

/*	utils	*/
/*		mlx_utils.c	*/
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);
/*		utils.c	*/
int			clean_exit(t_game *game);

#endif
