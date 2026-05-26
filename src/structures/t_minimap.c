/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:17:39 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/26 16:51:01 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_minimap	t_minimap_new(t_map map, t_ray ray)
{
	t_minimap	minimap;

	minimap.cell_size = ATH_SIZE / map.width;
	if (minimap.cell_size < ATH_SIZE / map.height)
		minimap.cell_size = ATH_SIZE / map.height;
	minimap.width = minimap.cell_size * map.width;
	minimap.height = minimap.cell_size * map.height;
	minimap.p_radius = (ATH_SIZE / 100 * 2);
	minimap.p_posx = ray.posx * minimap.cell_size;
	minimap.p_posy = ray.posy * minimap.cell_size;
	return (minimap);
}

void	t_minimap_update(t_minimap *minimap, t_ray	ray)
{
	minimap->p_posx = ray.posx * minimap->cell_size;
	minimap->p_posy = ray.posy * minimap->cell_size;
}
