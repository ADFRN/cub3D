/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:21:31 by afournie          #+#    #+#             */
/*   Updated: 2026/06/22 16:29:58 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
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
		while (map[y][x] && map[y][x] != '\n')
		{
			c = map[y][x];
			if (is_player(c))
				(*player_count)++;
			else if (c != FLOOR && c != WALL && c != DOOR && c != ' '
				&& c != '\t')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	check_map(char **map)
{
	char	**copy;
	int		player_count;
	int		py;
	int		px;

	player_count = 0;
	if (!check_chars(map, &player_count))
		return (ft_putendl_fd("error: invalid character in the map",
				STDERR_FILENO), false);
	if (player_count != 1)
		return (ft_putendl_fd("error: expect one player in the map",
				STDERR_FILENO), false);
	copy = copy_map(map);
	if (!copy)
		return (false);
	if (!find_player(copy, &py, &px))
		return (ft_putendl_fd("error: map problem", STDERR_FILENO),
			free_map(copy), false);
	if (!flood_fill(copy, py, px))
		return (ft_putendl_fd("error: map problem", STDERR_FILENO),
			free_map(copy), false);
	free_map(copy);
	return (true);
}
