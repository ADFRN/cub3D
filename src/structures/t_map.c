/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:21:46 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/28 16:17:29 by afournie         ###   ########.fr       */
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

	map.has_ceiling = 0;
	map.has_floor = 0;
	map.has_no = 0;
	map.has_so = 0;
	map.has_ea = 0;
	map.has_we = 0;
	map.ceiling_color = 0;
	map.floor_color = 0;
	map.ea_txt = NULL;
	map.so_txt = NULL;
	map.no_txt = NULL;
	map.we_txt = NULL;
	map.doors = NULL;
	map.height = 0;
	map.width = 0;
	map.map = NULL;
	return (map);
}

t_map	t_map_new(t_game *game, char *map_path)
{
	t_map	map_data;

	map_data = t_map_init();
	if (!get_map_info(&map_data, map_path))
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
	if (map->ea_txt)
		free(map->ea_txt);
	if (map->so_txt)
		free(map->so_txt);
	if (map->no_txt)
		free(map->no_txt);
	if (map->we_txt)
		free(map->we_txt);
	if (map->doors)
		free(map->doors);
}
