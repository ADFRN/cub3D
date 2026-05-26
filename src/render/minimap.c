/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:50:25 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/26 12:11:59 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_cell(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;
	int	cell_size;

	cell_size = game->minimap.cell_size;
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

static void	fill_minimap(t_game *game, int ground_color, int wall_color)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == WALL)
				fill_cell(game, x, y, wall_color);
			else if (game->map.map[y][x] == FLOOR)
				fill_cell(game, x, y, ground_color);
			else
				fill_cell(game, x, y, BLACK);
			x++;
		}
		y++;
	}
}

void	minimap(t_game *game, int ground_c, int wall_c, int player_c)
{
	fill_minimap(game, ground_c, wall_c);
	t_minimap_update(&game->minimap, game->ray);
	draw_player(
		game,
		game->minimap.p_posx,
		game->minimap.p_posy,
		player_c);
	draw_raycast(game);
}
