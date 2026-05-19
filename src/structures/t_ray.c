/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ray.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:42:15 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/19 10:41:19 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_ray	t_ray_new(void)
{
	t_ray	ray;

	ray.camerax = 0;
	ray.dirx = 0;
	ray.diry = 0;
	ray.mapx = 0;
	ray.mapy = 0;
	ray.posx = 0;
	ray.posy = 0;
	ray.delta_dist_x = 0;
	ray.delta_dist_y = 0;
	ray.hit = false;
	ray.side = 0;
	return (ray);
}

void	t_ray_update(t_game *game, t_ray *ray, int x)
{
	int		cell_w;
	int		cell_h;

	cell_w = WIN_WIDTH / game->map.width;
	cell_h = WIN_HEIGHT / game->map.height;
	ray->camerax = 2.0 * x / (double)WIN_WIDTH - 1.0;
	ray->dirx = game->player.dirx + game->player.planex * ray->camerax;
	ray->diry = game->player.diry + game->player.planey * ray->camerax;
	ray->mapx = (int)(game->player.posx / cell_w);
	ray->mapy = (int)(game->player.posy / cell_h);
	ray->posx = game->player.posx / cell_w;
	ray->posy = game->player.posy / cell_h;
	ray->delta_dist_x = fabs(1.0 / ray->dirx);
	ray->delta_dist_y = fabs(1.0 / ray->diry);
	ray->hit = false;
	ray->side = 0;
}
