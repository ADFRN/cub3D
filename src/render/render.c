/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:27:17 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/12 22:37:45 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render_next_frame(t_game *game)
{
	static long	last_frame = 0;
	long		now;

	now = get_time_us();
	if (now - last_frame < FRAME_TIME)
		return (0);
	last_frame = now;

	update_player_position(game);
	fill_image(game, 0x00FFFFFF, 0x0082C8E5);
	draw_circle(
		game,
		game->player.posX,
		game->player.posY,
		game->player.radius,
		0x00FF0000);
	draw_raycast(game);
	mlx_put_image_to_window(game->mlx, game->win , game->data.img, 0, 0);
	return (0);
}
