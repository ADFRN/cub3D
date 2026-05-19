/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:28:31 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/19 10:45:33 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dirx;
	player->dirx = old_dir_x * cos(angle) - player->diry * sin(angle);
	player->diry = old_dir_x * sin(angle) + player->diry * cos(angle);
	old_plane_x = player->planex;
	player->planex = old_plane_x * cos(angle) - player->planey * sin(angle);
	player->planey = old_plane_x * sin(angle) + player->planey * cos(angle);
	player->raydir_x = player->dirx + player->planex * player->camerax;
	player->raydir_y = player->diry + player->planey * player->camerax;
}

static void	move_player(t_game *game, double delta_x, double delta_y)
{
	int	cell_w;
	int	cell_h;
	int	map_x;
	int	map_y;

	cell_w = WIN_WIDTH / game->map.width;
	cell_h = WIN_HEIGHT / game->map.height;
	map_x = (game->player.posx + delta_x) / cell_w;
	map_y = (game->player.posy + delta_y) / cell_h;
	if (map_y >= game->map.height)
		map_y = game->map.height - 1;
	if (map_x >= game->map.width)
		map_x = game->map.width - 1;
	if (game->map.map[map_y][map_x] != '1')
	{
		game->player.posx += delta_x;
		game->player.posy += delta_y;
	}
}

static void	update_player_pos(t_game *game, t_player *p, t_keys keys)
{
	if (game->keys.shift)
		game->player.mov_speed *= SPEED_MULT;
	if (keys.w)
		move_player(game, p->dirx * p->mov_speed, p->diry * p->mov_speed);
	if (keys.s)
		move_player(game, -(p->dirx * p->mov_speed), -(p->diry * p->mov_speed));
	if (keys.a)
		move_player(game, p->diry * p->mov_speed, -(p->dirx * p->mov_speed));
	if (keys.d)
		move_player(game, -(p->diry * p->mov_speed), p->dirx * p->mov_speed);
}

static void	update_player_dir(t_game *game, int radius)
{
	if (game->keys.right)
		rotate_player(&game->player, game->player.rot_speed);
	if (game->keys.left)
		rotate_player(&game->player, -game->player.rot_speed);
	if (game->player.posx - radius < 0)
		game->player.posx = radius;
	if (game->player.posx + radius > WIN_WIDTH)
		game->player.posx = WIN_WIDTH - radius;
	if (game->player.posy - radius < 0)
		game->player.posy = radius;
	if (game->player.posy + radius > WIN_HEIGHT)
		game->player.posy = WIN_HEIGHT - radius;
}

void	update_player(t_game *game)
{
	update_player_pos(game, &game->player, game->keys);
	update_player_dir(game, game->player.radius);
}
