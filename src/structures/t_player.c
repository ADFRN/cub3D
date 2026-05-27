/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:21:43 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/27 14:25:36 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	get_player_dir(char c, t_player *player)
{
	if (c == 'N')
	{
		player->dirx = 0;
		player->diry = -1;
		return ;
	}
	if (c == 'S')
	{
		player->dirx = 0;
		player->diry = 1;
		return ;
	}
	if (c == 'E')
	{
		player->dirx = 1;
		player->diry = 0;
		return ;
	}
	if (c == 'W')
	{
		player->dirx = -1;
		player->diry = 0;
		return ;
	}
}

static void	get_player_pos(t_game game, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (game.map.map[y])
	{
		x = 0;
		while (game.map.map[y][x])
		{
			if (is_player(game.map.map[y][x]))
			{
				player->posx = (WIN_WIDTH * 1.0 / game.map.width) * x;
				player->posy = (WIN_HEIGHT * 1.0 / game.map.height) * y;
				get_player_dir(game.map.map[y][x], player);
				return ;
			}
			x++;
		}
		y++;
	}
}

t_player	t_player_new(t_game game)
{
	t_player	player;

	player.radius = (ATH_SIZE / 100 * 2);
	player.mov_speed = 0;
	player.rot_speed = 0;
	get_player_pos(game, &player);
	player.planex = -player.diry * (tan(FOV * M_PI / 180 / 2));
	player.planey = player.dirx * (tan(FOV * M_PI / 180 / 2));
	player.raydir_x = 0;
	player.raydir_y = 0;
	player.camerax = 0;
	return (player);
}
