/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:28:31 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/18 17:24:42 by ttiprez          ###   ########.fr       */
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

//static bool	is_wall(t_game *game, int pos_x, int pos_y)
//{
//	int	cell_w;
//	int	cell_h;

//	cell_w = WIN_WIDTH / game->map.width;
//	cell_h = WIN_HEIGHT / game->map.height;
//	if (pos_y >= game->map.height)
//		pos_y = game->map.height - 1;
//	if (pos_x >= game->map.width)
//		pos_x = game->map.width - 1;
//	printf("map[%d][%d] = %c\n", pos_y, pos_x, game->map.map[pos_y/cell_h][pos_x/cell_w]);
//	return (false);
//}

static void	update_player_pos(t_game *game, t_player *p, t_keys keys)
{
	double	speed;
	(void)game;

	speed = p->mov_speed;
	if (keys.w)
	{
		p->posX += p->dirX * speed;
		p->posY += p->dirY * speed;
	}
	if (keys.s)
	{
		p->posX -= p->dirX * speed;
		p->posY -= p->dirY * speed;
	}
	if (keys.a)
	{
		p->posX += p->dirY * speed;
		p->posY -= p->dirX * speed;
	}
	if (keys.d)
	{
		p->posX -= p->dirY * speed;
		p->posY += p->dirX * speed;
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

void	update_player(t_game *game)
{
	update_player_pos(game, &game->player, game->keys);
	update_player_dir(game, game->player.radius);
}
