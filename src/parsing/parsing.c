/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:56:04 by afournie          #+#    #+#             */
/*   Updated: 2026/06/23 15:01:16 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	is_map(char *line, t_textures *t)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
		|| line[i] == 'F' || line[i] == 'C')
		return (false);
	else if (line[i] == '\n')
		return (t->has_ceiling && t->has_floor && t->ea.has_tex && t->no.has_tex
			&& t->so.has_tex && t->we.has_tex);
	return (true);
}

static bool	stock_info(t_textures *tex, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\n')
		return (true);
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		return (get_textures(tex, line));
	else if (line[i] == 'F' || line[i] == 'C')
		return (get_colors(tex, line));
	else if (line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
		&& line[i] != 'E' && line[i] != 'F' && line[i] != 'C')
		return (ft_putendl_fd("Error\ninvalid character", STDERR_FILENO),
			false);
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

static bool	info_while(t_game *g, t_map *map, char *line, int *size)
{
	if (!is_map(line, &g->tex))
		return (stock_info(&g->tex, line));
	else
	{
		if (!g->tex.has_ceiling || !g->tex.has_floor || !g->tex.ea.has_tex
			|| !g->tex.no.has_tex || !g->tex.so.has_tex || !g->tex.we.has_tex)
			return (ft_putendl_fd("Error\ncub file invalid", STDERR_FILENO),
				false);
		if (*size == 0 && line[0] == '\n')
			return (true);
		line = expand_tabs(line);
		map->map = expand_map(map->map, *size, line);
		free(line);
		(*size)++;
	}
	return (true);
}

bool	get_map_info(t_game *game, t_map *map, char *map_path)
{
	int		fd;
	char	*line;
	int		size;

	size = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Error\nfile not found", STDERR_FILENO), false);
	line = get_next_line(fd);
	while (line)
	{
		if (!info_while(game, map, line, &size))
			return (free(line), false);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (!verify_all_data(map, &game->tex))
		return (false);
	return (true);
}
