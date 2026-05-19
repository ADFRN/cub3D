/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:21:43 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/19 10:47:04 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_player	t_player_new(void)
{
	t_player	player;

	player.radius = (ATH_SIZE / 100 * 2);
	player.mov_speed = 0;
	player.rot_speed = 0;
	player.posx = 100;
	player.posy = 100;
	player.dirx = 1;
	player.diry = 0;
	player.planex = -player.diry * (tan(FOV * M_PI / 180 / 2));
	player.planey = player.dirx * (tan(FOV * M_PI / 180 / 2));
	player.raydir_x = 0;
	player.raydir_y = 0;
	player.camerax = 0;
	return (player);
}
