/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:56:04 by afournie          #+#    #+#             */
/*   Updated: 2026/05/15 15:05:43 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
		|| line[i] == 'F' || line[i] == 'C' || line[i] == '\n')
		return (false);
	else
		return (true);
}

static void	stock_info(t_map *map, char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
	{
		if (!get_textures(map, line))
			exit(1);
	}
	else if (line[i] == 'F' || line[i] == 'C')
	{
		if (!get_colors(map, line))
			exit(1);
	}
	else
		return ;
}

static char	**expand_map(char **old_map, int old_size, char *new_line)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (old_size + 2));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		new_map[i] = old_map[i];
		i++;
	}
	new_map[old_size] = new_line;
	new_map[old_size + 1] = NULL;
	free(old_map);
	return (new_map);
}


void	get_map_info(t_map *map, char *map_path)
{
	int		fd;
	char	*line;
	int		size;

	size = 0;
	map->map = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		if (!is_map(line))
			stock_info(map, line);
		else
		{
			map->height = size;
			map->map = expand_map(map->map, size, line);
			size++;
		}
		line = get_next_line(fd);
	}
	close(fd);
}
