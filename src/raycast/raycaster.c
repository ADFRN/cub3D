/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:52:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/14 12:52:20 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_step(t_ray *ray)
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

static void	dda_loop(t_game *game, t_ray *ray)
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

static void	draw_column(t_game *game, t_ray *ray, int x)
{
	double	perpWallDist;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		y;

	if (ray->side == 0)
		perpWallDist = ray->sideDistX - ray->deltaDistX;
	else
		perpWallDist = ray->sideDistY - ray->deltaDistY;
	lineHeight = (int)(WIN_HEIGHT / perpWallDist);
	drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
	if (drawEnd >= WIN_HEIGHT)
		drawEnd = WIN_HEIGHT - 1;
	y = drawStart;
	while (y < drawEnd)
	{
		ft_mlx_pixel_put(&game->data, x, y, 0x009E9E9E);
		y++;
	}
}

void	raycast(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		t_ray_init(game, &ray, x);
		init_step(&ray);
		dda_loop(game, &ray);
		draw_column(game, &ray, x);
		x++;
	}
}

