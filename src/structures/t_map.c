/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:21:46 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/18 12:46:40 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map	init_map(void)
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
	map.height = 0;
	map.width = 0;
	map.map = NULL;
	return (map);
}

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

t_map	t_map_new(char **map)
{
	t_map	map_data;

	map_data.map = map;
	map_data.height = map_height_len(map);
	map_data.width = map_width_len(map);
	return (map_data);
}
