/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:27:17 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/15 17:25:20 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	calculate_rot_mov_speed(t_game *game)
{
	long		time;
	double		delta;
	
	time = get_time_us();
	delta = (time - game->last_frame) / 1000000.0;
	game->last_frame = time;
	game->player.mov_speed = MOV_SPEED * delta;
	game->player.rot_speed = ROT_SPEED * delta;
}

static void	minimap(t_game *game, int ground_c, int wall_c, int player_c)
{
	fill_minimap(game, ground_c, wall_c);
	draw_circle(
		game,
		game->player.posX,
		game->player.posY,
		game->player.radius,
		player_c);
	draw_raycast(game);
}

static void	sky_and_ground(t_game *game, int ground, int ceiling)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				ft_mlx_pixel_put(&game->data, x, y, ceiling);
			else
				ft_mlx_pixel_put(&game->data, x, y, ground);
			x++;
		}
		y++;
	}
}

int	render_next_frame(t_game *game)
{
	if (get_time_us() - game->last_frame < FRAME_TIME)
		return (0);
	calculate_rot_mov_speed(game);
	update_player(game);
	sky_and_ground(game, BLACK, BLACK);
	raycast(game);
	minimap(game, WHITE, SKY_BLUE, RED);
	mlx_put_image_to_window(game->mlx, game->win , game->data.img, 0, 0);
	return (0);
}
