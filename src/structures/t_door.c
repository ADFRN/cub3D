/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_door.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:29:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/27 13:33:19 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	count_doors(char **map)
{
	int	x;
	int	y;
	int	nb_doors;

	nb_doors = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			nb_doors += map[y][x] == DOOR;
	}
	return (nb_doors);
}

t_door	t_door_new(t_door_state state, int map_x, int map_y, int nb_doors)
{
	t_door door;

	door.state = state;
	door.nb_doors = nb_doors;
	door.map_x = map_x;
	door.map_y = map_y;
	return (door);
}

void	t_door_fill(t_game *game, t_map *map)
{
	int	x;
	int	y;
	int	doors_i;
	int	nb_doors;

	nb_doors = count_doors(map->map);
	map->doors = malloc(sizeof(t_door) * (nb_doors + 1));
	map->doors[nb_doors] = t_door_new(DOOR_UNDEFINED, -1, -1, nb_doors);
	if (!map->doors)
		clean_exit(game);
	doors_i = -1;
	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
			if (map->map[y][x] == DOOR)
				map->doors[++doors_i] = t_door_new(DOOR_CLOSE, x, y, nb_doors);
	}
}

t_door	*t_door_get(t_door *doors, int map_x, int map_y)
{
	int	i;

	i = -1;
	while (++i < doors[0].nb_doors)
		if (doors[i].map_x == map_x && doors[i].map_y == map_y)
			return (&doors[i]);
	return (&doors[i]);
}

void	t_door_state_switch(t_door *door)
{
	if (door->state == DOOR_OPEN)
		door->state = DOOR_CLOSE;
	else if (door->state == DOOR_CLOSE)
		door->state = DOOR_OPEN;
}
