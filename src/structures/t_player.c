/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:21:43 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/10 19:56:21 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_player	t_player_new()
{
	t_player player;

	player.radius = 10;
	player.dirX = 0;
	player.dirY = 0;
	player.posX = 50;
	player.posY = 50;
	return (player);
}
