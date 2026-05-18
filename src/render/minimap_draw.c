/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:27:15 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/18 13:21:38 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void draw_ray(t_game *g, double x, double y, double dirX, double dirY)
{
	int i;
	int px;
	int py;

	i = 0;
	while (i < RENDER_DIST)
	{
		px = x + (int)(dirX * i);
		py = y + (int)(dirY * i);
		if (px < 0 || px >= WIN_WIDTH || py < 0 || py >= WIN_HEIGHT)
			break ;
		ft_mlx_pixel_put(&g->data, px, py, RED);
		i++;
	}
}

void	draw_player(t_game *game, int cx, int cy, int color)
{
	int	x;
	int	y;
	int	radius;
	
	radius = 1;
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius && cx < WIN_WIDTH && cy < WIN_HEIGHT)
				ft_mlx_pixel_put(&game->data, cx + x, cy + y, color);
			x++;
		}
		y++;
	}
}

void	draw_raycast(t_game *game)
{
	t_player	*player;

	player = &game->player;
	for (int x = 0; x < WIN_WIDTH; x += WIN_WIDTH / 30	)
	{
		player->cameraX = 2.0 * x / (double)WIN_WIDTH - 1.0;
		player->rayDirX = player->dirX + player->planeX * player->cameraX;
		player->rayDirY = player->dirY + player->planeY * player->cameraX;
		draw_ray(game,
			game->minimap.p_posX,
			game->minimap.p_posY,
			player->rayDirX,
			player->rayDirY);
	}
}
