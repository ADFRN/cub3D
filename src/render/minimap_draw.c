/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:27:15 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/18 16:07:30 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void draw_ray(t_game *game, t_player *player, int x, int range)
{
	int i;
	int px;
	int py;

	player->cameraX = 2.0 * x / (double)WIN_WIDTH - 1.0;
	player->rayDirX = player->dirX + player->planeX * player->cameraX;
	player->rayDirY = player->dirY + player->planeY * player->cameraX;
	i = 0;
	while (i < range)
	{
		px = game->minimap.p_posX + (int)(player->rayDirX * i);
		py = game->minimap.p_posY + (int)(player->rayDirY * i);
		if (px < 0 || px >= WIN_WIDTH || py < 0 || py >= WIN_HEIGHT)
			break ;
		ft_mlx_pixel_put(&game->data, px, py, RED);
		i++;
	}
}

void	draw_player(t_game *game, int cx, int cy, int color)
{
	int	x;
	int	y;
	int	radius;
	
	radius = PLAYER_RADIUS;
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius && cx < WIN_WIDTH
				&& cy < WIN_HEIGHT && cy + y > 0)
				ft_mlx_pixel_put(&game->data, cx + x, cy + y, color);
			x++;
		}
		y++;
	}
}

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

static int	get_perpWallDist(t_ray *ray)
{
	int	perpWallDist;

	if (ray->side == 0)
		perpWallDist = ray->sideDistX - ray->deltaDistX;
	else
		perpWallDist = ray->sideDistY - ray->deltaDistY;
	return (perpWallDist);
}

void	draw_raycast(t_game *game)
{
	t_ray	ray = t_ray_new();
	int		x;

	x = 0;
	for (int x = 0; x < WIN_WIDTH; x++)
	{
		t_ray_update(game, &ray, x);
		init_step(&ray);
		dda_loop(game, &ray);
		int	dist = get_perpWallDist(&ray);
		dist *= game->minimap.cell_size;
		draw_ray(game, &game->player, x, dist);
	}
}
