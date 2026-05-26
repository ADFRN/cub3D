/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:21:26 by afournie          #+#    #+#             */
/*   Updated: 2026/05/26 11:39:32 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	flood_fill(char **map, int y, int x)
{
	if (y < 0 || x < 0)
		return (false);
	if (!map[y])
		return (false);
	if (x >= (int)ft_strlen(map[y]))
		return (false);
	if (map[y][x] == ' ')
		return (false);
	if (map[y][x] == '1')
		return (true);
	if (map[y][x] == 'F')
		return (true);
	map[y][x] = 'F';
	if (!flood_fill(map, y + 1, x))
		return (false);
	if (!flood_fill(map, y - 1, x))
		return (false);
	if (!flood_fill(map, y, x + 1))
		return (false);
	if (!flood_fill(map, y, x - 1))
		return (false);
	return (true);
}
