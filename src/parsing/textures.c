/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:56:06 by afournie          #+#    #+#             */
/*   Updated: 2026/05/15 15:04:22 by afournie         ###   ########.fr       */
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
	while (path[i])
	{
		tmp[y] = path[i];
		y++;
		i++;
	}
	tmp[y + 1] = '\0';
	return (tmp);
}

bool	get_textures(t_map *map, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (map->no_txt = cpy_textures(line), true);
	else if (!ft_strncmp(line, "SO", 2))
		return (map->so_txt = cpy_textures(line), true);
	else if (!ft_strncmp(line, "WE", 2))
		return (map->we_txt = cpy_textures(line), true);
	else if (!ft_strncmp(line, "EA", 2))
		return (map->ea_txt = cpy_textures(line), true);
	else
		return (printf("Error get_textures\n"), false);
}
