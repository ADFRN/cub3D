/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:21:46 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/26 12:08:32 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	map_height_len(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

static int	map_width_len(char **map)
{
	int	y;
	int	x;
	int	max_x;

	max_x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (max_x < x)
			max_x = x;
		y++;
	}
	return (max_x);
}

t_map	t_map_new(t_game *game, char **map)
{
	t_map	map_data;

	map_data.map = map;
	map_data.height = map_height_len(map);
	map_data.width = map_width_len(map);
	map_data.doors = NULL;
	t_door_fill(game, &map_data);
	return (map_data);
}
