/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:21:43 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/18 16:35:49 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_player	t_player_new(void)
{
	t_player	player;

	player.radius = PLAYER_RADIUS;
	player.mov_speed = 0;
	player.rot_speed = 0;
	player.posX = 100;
	player.posY = 100;
	player.dirX = 1;
	player.dirY = 0;
	player.planeX = -player.dirY * (tan(FOV * M_PI / 180 / 2));
	player.planeY = player.dirX * (tan(FOV * M_PI / 180 / 2));
	player.rayDirX = 0;
	player.rayDirY = 0;
	player.cameraX = 0;
	return (player);
}
