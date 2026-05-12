/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:27:15 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/12 16:07:27 by ttiprez          ###   ########.fr       */
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

void draw_direction_line(t_game *game)
{
	int	cx;
	int	cy;
	int	i;
	int	line_len;
	int	px;
	int	py;

	cx = game->player.posX;
	cy = game->player.posY;
	line_len = 100;
	i = 0;
	while (i < line_len)
	{
		px = cx + (int)(game->player.dirX * i);
		py = cy + (int)(game->player.dirY * i);
		if (px >= 0 && px < WIN_WIDTH && py >= 0 && py < WIN_HEIGHT)
			ft_mlx_pixel_put(&game->data, px, py, 0x00FF0000);
		i++;
	}
}

//void	draw_raycast(t_game *game)
//{
//	return ;
//}
