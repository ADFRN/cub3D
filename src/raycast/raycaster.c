/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:52:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/18 16:31:42 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static double	draw_column(t_game *game, t_ray *ray, int x)
{
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		y;

	if (ray->side == 0)
		perp_wall_dist = ray->sideDistX - ray->deltaDistX;
	else
		perp_wall_dist = ray->sideDistY - ray->deltaDistY;
	line_height = (int)(WIN_HEIGHT / perp_wall_dist);
	draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	y = draw_start;
	while (y < draw_end)
	{
		ft_mlx_pixel_put(&game->data, x, y, GREY);
		y++;
	}
	return (perp_wall_dist);
}

void	raycast(t_game *game)
{
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		t_ray_update(game, &game->ray, x);
		init_step(&game->ray);
		dda_loop(game, &game->ray);
		draw_column(game, &game->ray, x);
		x++;
	}
}

void	init_step(t_ray *ray)
{
	if (ray->dirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (ray->posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - ray->posX) * ray->deltaDistX;
	}
	if (ray->dirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (ray->posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - ray->posY) * ray->deltaDistY;
	}
}

void	dda_loop(t_game *game, t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (ray->mapX < 0 || ray->mapY < 0
			|| ray->mapX >= game->map.width
			|| ray->mapY >= game->map.height)
		{
			ray->hit = true;
			continue ;
		}
		if (game->map.map[ray->mapY][ray->mapX] == '1')
			ray->hit = true;
	}
}
