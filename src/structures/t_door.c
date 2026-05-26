/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_door.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:29:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/26 11:44:21 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_door	t_door_new(bool state, int map_x, int map_y)
{
	t_door door;
	
	door.state = state;
	door.pos_x = map_x;
	door.pos_y = map_y;
	return (door);
}

void	t_door_fill(t_game *game, t_map *map)
{
	int	map_x;
	int	map_y;
	int	doors_i;

	(void)game;
	map_y = -1;
	while (map->map[++map_y])
	{
		map_x = -1;
		while (map->map[map_y][++map_x])
			map->nb_doors += map->map[map_y][map_x] == DOOR;
	}
	printf("nb_doors = %d\n", map->nb_doors);
	map->doors = malloc(sizeof(t_door) * map->nb_doors);
	if (!map->doors)
		clean_exit(game);
	doors_i = -1;
	map_y = -1;
	while (map->map[++map_y])
	{
		map_x = -1;
		while (map->map[map_y][++map_x])
			if (map->map[map_y][map_x] == DOOR)
				map->doors[++doors_i] = t_door_new(false, map_x, map_y);
	}
}
