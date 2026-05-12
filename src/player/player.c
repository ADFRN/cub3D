/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:28:31 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/12 16:06:23 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void rotate_player(t_game *game, double angle)
{
	double  old_dir_x;
	double  old_plane_x;

	old_dir_x = game->player.dirX;
	game->player.dirX = old_dir_x * cos(angle) - game->player.dirY * sin(angle);
	game->player.dirY = old_dir_x * sin(angle) + game->player.dirY * cos(angle);

	old_plane_x = game->player.planeX;
	game->player.planeX = old_plane_x * cos(angle) - game->player.planeY * sin(angle);
	game->player.planeY = old_plane_x * sin(angle) + game->player.planeY * cos(angle);
}

void update_player_position(t_game *game)
{
	int radius;

	radius = game->player.radius;
	if (game->keys.w)
		game->player.posY -= 2;
	if (game->keys.s)
		game->player.posY += 2;
	if (game->keys.a)
		game->player.posX -= 2;
	if (game->keys.d)
		game->player.posX += 2;
	if (game->keys.right)
		rotate_player(game, ROT_SPEED);
	if (game->keys.left)
		rotate_player(game, -ROT_SPEED);

	// Clamp X
	if (game->player.posX - radius < 0)
		game->player.posX = radius;
	if (game->player.posX + radius > WIN_WIDTH)
		game->player.posX = WIN_WIDTH - radius;

	// Clamp Y
	if (game->player.posY - radius < 0)
		game->player.posY = radius;
	if (game->player.posY + radius > WIN_HEIGHT)
		game->player.posY = WIN_HEIGHT - radius;
}