/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:24:58 by afournie          #+#    #+#             */
/*   Updated: 2026/05/28 16:08:23 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_max_width(char **map)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][len - 1] == '\n')
			len--;
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

static char	*copy_line(char *line, int width)
{
	char	*new_line;
	int		x;

	new_line = malloc(sizeof(char) * (width + 1));
	if (!new_line)
		return (NULL);
	x = 0;
	while (x < width)
	{
		if (x < (int)ft_strlen(line) && line[x] != '\n')
			new_line[x] = line[x];
		else
			new_line[x] = ' ';
		x++;
	}
	new_line[x] = '\0';
	return (new_line);
}

char	**copy_map(char **map)
{
	char	**new_map;
	int		width;
	int		height;
	int		y;

	width = get_max_width(map);
	height = 0;
	while (map[height])
		height++;
	new_map = malloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	y = 0;
	while (y < height)
	{
		new_map[y] = copy_line(map[y], width);
		if (!new_map[y])
			return (NULL);
		y++;
	}
	new_map[y] = NULL;
	return (new_map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

bool	find_player(char **map, int *py, int *px)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_player(map[y][x]))
			{
				*py = y;
				*px = x;
				return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}
