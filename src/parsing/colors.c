/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:56:09 by afournie          #+#    #+#             */
/*   Updated: 2026/05/28 15:36:06 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\0')
			break ;
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

static int	parse_color(char *line)
{
	char	**colors;
	int		i;
	int		r;
	int		g;
	int		b;

	i = 0;
	r = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	colors = ft_split(line + i, ',');
	if (!is_valid_number(colors[0]) || !is_valid_number(colors[1])
		|| !is_valid_number(colors[2]) || colors[3] != NULL)
		exit((free_split(colors), ft_putendl_fd("Error\nInvalid color format",
					STDERR_FILENO), 1));
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	free_split(colors);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit((ft_putendl_fd("Error\nInvalid color value", STDERR_FILENO),
				EXIT_FAILURE));
	return (create_trgb(0, r, g, b));
}

bool	get_colors(t_map *map, char *line)
{
	if (!ft_strncmp(line, "F", 1))
	{
		if (map->has_floor)
			return (ft_putendl_fd("Error\nFloor color already set",
					STDERR_FILENO), false);
		map->floor_color = parse_color(line + 1);
		if (!map->floor_color)
			return (false);
		else
			return (map->has_floor = 1, true);
	}
	else if (!ft_strncmp(line, "C", 1))
	{
		if (map->has_ceiling)
			return (ft_putendl_fd("Error\nCeiling color already set",
					STDERR_FILENO), false);
		map->ceiling_color = parse_color(line + 1);
		if (!map->ceiling_color)
			return (false);
		else
			return (map->has_ceiling = 1, true);
	}
	else
		return (ft_putendl_fd("Error\nColors missing", STDERR_FILENO), false);
}
