/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:56:06 by afournie          #+#    #+#             */
/*   Updated: 2026/05/18 12:59:29 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*cpy_textures(char *path)
{
	int		i;
	int		y;
	int		size;
	char	*tmp;

	i = 2;
	y = 0;
	while (path[i] == ' ' || path[i] == '\t')
		i++;
	size = ft_strlen(path + i);
	tmp = malloc((sizeof(char) * size) + 1);
	if (!tmp)
		exit(1);
	while (path[i] && path[i] != '\n')
	{
		tmp[y] = path[i];
		y++;
		i++;
	}
	tmp[y] = '\0';
	return (tmp);
}

static bool	textures_ns(t_map *map, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
	{
		if (map->has_no)
			return (ft_putendl_fd("Error\nNO textures already set",
					STDERR_FILENO), false);
		map->no_txt = cpy_textures(line);
		if (!map->no_txt)
			return (false);
		else
			return (map->has_no = 1, true);
	}
	else
	{
		if (map->has_so)
			return (ft_putendl_fd("Error\nSO textures already set",
					STDERR_FILENO), false);
		map->so_txt = cpy_textures(line);
		if (!map->so_txt)
			return (false);
		else
			return (map->has_so = 1, true);
	}
}

static bool	textures_we(t_map *map, char *line)
{
	if (!ft_strncmp(line, "WE", 2))
	{
		if (map->has_we)
			return (ft_putendl_fd("Error\nWE textures already set",
					STDERR_FILENO), false);
		map->we_txt = cpy_textures(line);
		if (!map->we_txt)
			return (false);
		else
			return (map->has_we = 1, true);
	}
	else
	{
		if (map->has_ea)
			return (ft_putendl_fd("Error\nEA textures already set",
					STDERR_FILENO), false);
		map->ea_txt = cpy_textures(line);
		if (!map->ea_txt)
			return (false);
		else
			return (map->has_ea = 1, true);
	}
}

bool	get_textures(t_map *map, char *line)
{
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2))
		return (textures_ns(map, line));
	else if (!ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		return (textures_we(map, line));
	else
		return (ft_putendl_fd("Error\nCheck textures", STDERR_FILENO), false);
}
