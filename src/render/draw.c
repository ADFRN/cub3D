/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:27:15 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/15 17:24:32 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_cell(t_game *game, int x, int y, int color)
{
	int	cell_size;
	int	i;
	int	j;

	cell_size = ATH_SIZE / game->map.width;
	if (ATH_SIZE / game->map.width < ATH_SIZE / game->map.height)
		cell_size = ATH_SIZE / game->map.height;
	i = -1;
	while (++i < cell_size)
	{
		j = -1;
		while (++j < cell_size)
		{
			if (i == 0 || j == 0)
				ft_mlx_pixel_put(
					&game->data,
					(x * cell_size + j), (y * cell_size + i), 0x00000000);
			else
				ft_mlx_pixel_put(
					&game->data,
					(x * cell_size + j), (y * cell_size + i), color);
		}
	}
}

void	fill_minimap(t_game *game, int ground_color, int wall_color)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				fill_cell(game, x, y, wall_color);
			else if (game->map.map[y][x] == '0')
				fill_cell(game, x, y, ground_color);
			else
				fill_cell(game, x, y, BLACK);
			x++;
		}
		y++;
	}
}

void	draw_circle(t_game *game, int cx, int cy, int radius, int color)
{
	int	x;
	int	y;

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

static void draw_ray(t_game *game, double x, double y, double dirX, double dirY)
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
		ft_mlx_pixel_put(&game->data, px, py, RED);
		i++;
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
			player->posX,
			player->posY,
			player->rayDirX,
			player->rayDirY);
	}
}
