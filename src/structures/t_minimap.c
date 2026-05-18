/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:17:39 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/18 13:10:41 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_minimap	t_minimap_new(t_map map, t_ray ray)
{
	t_minimap	minimap;

	//ray->posX = game->player.posX / cell_w;
	minimap.cell_size = ATH_SIZE / map.width;
	if (minimap.cell_size < ATH_SIZE / map.height)
		minimap.cell_size = ATH_SIZE / map.height;
	minimap.width = minimap.cell_size * map.width;
	minimap.height = minimap.cell_size * map.height;
	minimap.p_radius = PLAYER_RADIUS;
	minimap.p_posX = ray.posX * minimap.cell_size;
	minimap.p_posY = ray.posY * minimap.cell_size;
	return (minimap);
}

void	t_minimap_update(t_minimap *minimap, t_ray	ray)
{
	minimap->p_posX = ray.posX * minimap->cell_size;
	minimap->p_posY = ray.posY * minimap->cell_size;
}