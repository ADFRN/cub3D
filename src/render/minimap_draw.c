/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:27:15 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/18 16:21:12 by ttiprez          ###   ########.fr       */
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

static double	get_perpWallDist(t_ray *ray)
{
	double	perpWallDist;

	if (ray->side == 0)
		perpWallDist = ray->sideDistX - ray->deltaDistX;
	else
		perpWallDist = ray->sideDistY - ray->deltaDistY;
	return (perpWallDist);
}

void	draw_raycast(t_game *game)
{
	int		x;
	int		cell_size;
	t_ray	ray = t_ray_new();

	x = 0;
	cell_size = game->minimap.cell_size;
	for (int x = 0; x < WIN_WIDTH; x++)
	{
		t_ray_update(game, &ray, x);
		init_step(&ray);
		dda_loop(game, &ray);
		draw_ray(game, &game->player, x, get_perpWallDist(&ray) * cell_size);
	}
}
