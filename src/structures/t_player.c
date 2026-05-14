/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:21:43 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/14 11:45:15 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_player	t_player_new()
{
	t_player	player;
	double		fov_rad;

	fov_rad = FOV * M_PI / 180;
	player.radius = 10;
	player.mov_speed = 0;
	player.rot_speed = 0;
	player.posX = 50;
	player.posY = 50;
	player.dirX = -1;
	player.dirY = 0;
	player.planeX = 0;
	player.planeY = -(tan(fov_rad / 2));
	player.rayDirX = 0;
	player.rayDirY = 0;
	player.cameraX = 0;
	return (player);
}
