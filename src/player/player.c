/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:28:31 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/14 12:49:39 by ttiprez          ###   ########.fr       */
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

	player->rayDirX = player->dirX + player->planeX * player->cameraX;
	player->rayDirY = player->dirY + player->planeY * player->cameraX;
}

static void update_player_pos(t_game *game)
{
	double	speed;

	speed = game->player.mov_speed;
	if (game->keys.w)
	{
		game->player.posX += game->player.dirX * speed;
		game->player.posY += game->player.dirY * speed;
	}
	if (game->keys.s)
	{
		game->player.posX -= game->player.dirX * speed;
		game->player.posY -= game->player.dirY * speed;
	}
	if (game->keys.a)
	{
		game->player.posX += game->player.dirY * speed;
		game->player.posY -= game->player.dirX * speed;
	}
	if (game->keys.d)
	{
		game->player.posX -= game->player.dirY * speed;
		game->player.posY += game->player.dirX * speed;
	}
}

static void	update_player_dir(t_game *game, int radius)
{
	if (game->keys.right)
		rotate_player(&game->player, game->player.rot_speed);
	if (game->keys.left)
		rotate_player(&game->player, -game->player.rot_speed);
	if (game->player.posX - radius < 0)
		game->player.posX = radius;
	if (game->player.posX + radius > WIN_WIDTH)
		game->player.posX = WIN_WIDTH - radius;
	if (game->player.posY - radius < 0)
		game->player.posY = radius;
	if (game->player.posY + radius > WIN_HEIGHT)
		game->player.posY = WIN_HEIGHT - radius;
}

void update_player(t_game *game)
{
	update_player_pos(game);
	update_player_dir(game, game->player.radius);
}
