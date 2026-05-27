/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:13:31 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/27 14:30:47 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_player(t_player *player, double angle)
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
