/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:27:15 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/12 22:43:02 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_cell(t_game *game, int x, int y, int color)
{
	int	cell_width;
	int	cell_height;
	int	i;
	int	j;

	cell_width = WIN_WIDTH / game->map.map_width;
	cell_height = WIN_HEIGHT / game->map.map_height;
	i = -1;
	while (++i < cell_height)
	{
		j = -1;
		while (++j < cell_width)
		{
			if (i == 0 || j == 0)
				ft_mlx_pixel_put(
					&game->data,
					(x * cell_width + j), (y * cell_height + i), 0x00000000);
			else
				ft_mlx_pixel_put(
					&game->data,
					(x * cell_width + j), (y * cell_height + i), color);
		}
	}
}

void	fill_image(t_game *game, int ground_color, int wall_color)
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
				fill_cell(game, x, y, 0x00000000);
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
    int len;

    i = 0;
    len = RENDER_DIST;
    while (i < len)
    {
        px = x + (int)(dirX * i);
        py = y + (int)(dirY * i);
        if (px < 0 || px >= WIN_WIDTH || py < 0 || py >= WIN_HEIGHT)
            break;
        ft_mlx_pixel_put(&game->data, px, py, 0x00FF0000);
        i++;
    }
}

void	draw_raycast(t_game *game)
{
	double cameraX;
	double rayDirX;
	double rayDirY;
	for (int x = 0; x < WIN_WIDTH; x += WIN_WIDTH / 30	)
	{
		cameraX = 2.0 * x / (double)WIN_WIDTH - 1.0;
		rayDirX = game->player.dirX + game->player.planeX * cameraX;
		rayDirY = game->player.dirY + game->player.planeY * cameraX;
		draw_ray(game,
			game->player.posX,
			game->player.posY,
			rayDirX,
			rayDirY);
	}
}
