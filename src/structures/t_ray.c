/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ray.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:42:15 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/18 13:09:57 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_ray	t_ray_new()
{
	t_ray	ray;

	ray.cameraX = 0;
	ray.dirX = 0;
	ray.dirY = 0;
	ray.mapX = 0;
	ray.mapY = 0;
	ray.posX = 0;
	ray.posY = 0;
	ray.deltaDistX = 0;
	ray.deltaDistY = 0;
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
	ray->cameraX = 2.0 * x / (double)WIN_WIDTH - 1.0;
	ray->dirX = game->player.dirX + game->player.planeX * ray->cameraX;
	ray->dirY = game->player.dirY + game->player.planeY * ray->cameraX;
	ray->mapX = (int)(game->player.posX / cell_w);
	ray->mapY = (int)(game->player.posY / cell_h);
	ray->posX = game->player.posX / cell_w;
	ray->posY = game->player.posY / cell_h;
	ray->deltaDistX = fabs(1.0 / ray->dirX);
	ray->deltaDistY = fabs(1.0 / ray->dirY);
	ray->hit = false;
	ray->side = 0;
}
