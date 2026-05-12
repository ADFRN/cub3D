/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:28:31 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/12 22:29:56 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void rotate_player(t_player *player, double angle)
{
	double  old_dir_x;
	double  old_plane_x;

	old_dir_x = player->dirX;
	player->dirX = old_dir_x * cos(angle) - player->dirY * sin(angle);
	player->dirY = old_dir_x * sin(angle) + player->dirY * cos(angle);

	old_plane_x = player->planeX;
	player->planeX = old_plane_x * cos(angle) - player->planeY * sin(angle);
	player->planeY = old_plane_x * sin(angle) + player->planeY * cos(angle);
}

static void	update_rayDir(t_player *player)
{
	player->rayDirX = player->dirX + player->planeX * player->cameraX;
	player->rayDirY = player->dirY + player->planeY * player->cameraX;
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
	{
		rotate_player(&game->player, ROT_SPEED);
		update_rayDir(&game->player);
	}
	if (game->keys.left)
	{
		rotate_player(&game->player, -ROT_SPEED);
		update_rayDir(&game->player);
	}

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