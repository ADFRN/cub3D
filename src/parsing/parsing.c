/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:56:04 by afournie          #+#    #+#             */
/*   Updated: 2026/05/26 16:56:55 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	is_map(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
		|| line[i] == 'F' || line[i] == 'C')
		return (false);
	else if (line[i] == '\n')
	{
		if (map->has_ceiling && map->has_ea && map->has_no && map->has_floor
			&& map->has_so && map->has_we)
			return (true);
		else
			return (false);
	}
	else
		return (true);
}

static bool	stock_info(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\n')
		return (true);
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		return (get_textures(map, line));
	else if (line[i] == 'F' || line[i] == 'C')
		return (get_colors(map, line));
	else if (line[i] != 'N' || line[i] != 'S' || line[i] != 'W'
		|| line[i] != 'E' || line[i] != 'F' || line[i] != 'C')
		return (ft_putendl_fd("Error\nInvalid character", STDERR_FILENO),
			false);
	else
		return (true);
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
	new_map[old_size] = ft_strdup_classic(new_line);
	new_map[old_size + 1] = NULL;
	free(old_map);
	return (new_map);
}

static bool	info_while(t_map *map, char *line, int *size)
{
	if (!is_map(line, map))
		return (stock_info(map, line));
	else
	{
		if (!map->has_ceiling || !map->has_floor || !map->has_ea || !map->has_no
			|| !map->has_so || !map->has_we)
			return (ft_putendl_fd("Error\nMap before colors and textures",
					STDERR_FILENO), false);
		if (*size == 0 && line[0] == '\n')
			return (true);
		line = expand_tabs(line);
		map->map = expand_map(map->map, *size, line);
		(*size)++;
	}
	return (true);
}

bool	get_map_info(t_map *map, char *map_path)
{
	int		fd;
	char	*line;
	int		size;

	size = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	while (line)
	{
		if (!info_while(map, line, &size))
			return (false);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (!verify_all_data(map))
		return (false);
	return (true);
}
