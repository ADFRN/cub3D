/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:00:12 by afournie          #+#    #+#             */
/*   Updated: 2026/05/18 17:00:31 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_valid_cell(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == ' ')
		return (true);
	return (printf("valid_cell\n"), false);
}

static bool	check_flood_rules(char **map, int y, int x)
{
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
	{
		if (y == 0 || x == 0 || !map[y + 1] || !map[y][x + 1])
			return (false);
		if (is_valid_cell(map, y + 1, x) == 0)
			return (false);
		if (is_valid_cell(map, y - 1, x) == 0)
			return (false);
		if (is_valid_cell(map, y, x + 1) == 0)
			return (false);
		if (is_valid_cell(map, y, x - 1) == 0)
			return (false);
	}
	return (true);
}

static bool	check_chars(char **map, int *player_count)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			c = map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				(*player_count)++;
			else if (c != '0' && c != '1' && c != ' ' && c != '\t')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	check_map(char **map)
{
	int	y;
	int	player;
	int	x;

	y = 0;
	player = 0;
	if (!check_chars(map, &player))
		return (0);
	if (player != 1)
		return (false);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!check_flood_rules(map, y, x))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
