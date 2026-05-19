/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:28:31 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/19 10:33:57 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dirX;
	player->dirX = old_dir_x * cos(angle) - player->dirY * sin(angle);
	player->dirY = old_dir_x * sin(angle) + player->dirY * cos(angle);
	old_plane_x = player->planeX;
	player->planeX = old_plane_x * cos(angle) - player->planeY * sin(angle);
	player->planeY = old_plane_x * sin(angle) + player->planeY * cos(angle);
	player->rayDirX = player->dirX + player->planeX * player->cameraX;
	player->rayDirY = player->dirY + player->planeY * player->cameraX;
}

static void	move_player(t_game *game, double pos_x, double pos_y,
	double delta_x, double delta_y)
{
	int	cell_w;
	int	cell_h;
	int	map_x;
	int	map_y;

	cell_w = WIN_WIDTH / game->map.width;
	cell_h = WIN_HEIGHT / game->map.height;
	map_x = (pos_x + delta_x) / cell_w;
	map_y = (pos_y + delta_y) / cell_h;
	if (map_y >= game->map.height)
		map_y = game->map.height - 1;
	if (map_x >= game->map.width)
		map_x = game->map.width - 1;
	if (game->map.map[map_y][map_x] != '1')
	{
		game->player.posX += delta_x;
		game->player.posY += delta_y;
	}
}

static void	update_player_pos(t_game *game, t_player *p, t_keys keys)
{
	if (game->keys.shift)
		game->player.mov_speed *= SPEED_MULT;
	if (keys.w)
		move_player(game, p->posX, p->posY, 
			p->dirX * p->mov_speed, p->dirY * p->mov_speed);
	if (keys.s)
		move_player(game, p->posX, p->posY, 
			-(p->dirX * p->mov_speed), -(p->dirY * p->mov_speed));
	if (keys.a)
		move_player(game, p->posX, p->posY, 
			p->dirY * p->mov_speed, -(p->dirX * p->mov_speed));
	if (keys.d)
		move_player(game, p->posX, p->posY, 
			-(p->dirY * p->mov_speed), p->dirX * p->mov_speed);

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

void	update_player(t_game *game)
{
	update_player_pos(game, &game->player, game->keys);
	update_player_dir(game, game->player.radius);
}
