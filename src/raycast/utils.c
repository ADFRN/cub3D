/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:06:56 by afournie          #+#    #+#             */
/*   Updated: 2026/05/29 17:46:22 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_texture_pixel(t_img *tex, int x, int y)
{
	char	*dst;

	dst = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}

t_img	*get_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dirx < 0)
			return (&game->tex.we.tex);
		return (&game->tex.ea.tex);
	}
	if (game->map.map[ray->mapy][ray->mapx] == DOOR)
	{
		if (ray->diry < 0)
			return (&game->tex.ldoor.tex);
		else
			return (&game->tex.rdoor.tex);
	}
	if (ray->diry < 0)
		return (&game->tex.no.tex);
	return (&game->tex.so.tex);
}

double	get_perp_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		return (ray->side_dist_x - ray->delta_dist_x);
	return (ray->side_dist_y - ray->delta_dist_y);
}
