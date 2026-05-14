/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:27:17 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/14 12:49:53 by ttiprez          ###   ########.fr       */
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

int	render_next_frame(t_game *game)
{
	if (get_time_us() - game->last_frame < FRAME_TIME)
		return (0);
	calculate_rot_mov_speed(game);
	update_player(game);
	fill_image(game, 0x00FFFFFF, 0x0082C8E5);
	draw_circle(
		game,
		game->player.posX,
		game->player.posY,
		game->player.radius,
		0x00FF0000);
	raycast(game);
	draw_raycast(game);
	mlx_put_image_to_window(game->mlx, game->win , game->data.img, 0, 0);
	return (0);
}
