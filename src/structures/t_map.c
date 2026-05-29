/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:21:46 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/29 13:44:10 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	return (max_x - 1);
}

static int	map_height_len(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

static t_map	t_map_init(void)
{
	t_map	map;

	map.map = NULL;
	map.doors = NULL;
	map.height = 0;
	map.width = 0;
	return (map);
}

t_map	t_map_new(t_game *game, char *map_path)
{
	t_map	map_data;

	map_data = t_map_init();
	if (!get_map_info(game, &map_data, map_path))
		validation_failed_exit(game, &map_data);
	map_data.height = map_height_len(map_data.map);
	map_data.width = map_width_len(map_data.map);
	map_data.doors = NULL;
	t_door_fill(game, &map_data);
	return (map_data);
}

void	t_map_free(t_map *map)
{
	if (map->map)
		free_map(map->map);
	if (map->doors)
		free(map->doors);
}
