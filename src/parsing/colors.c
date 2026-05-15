/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:56:09 by afournie          #+#    #+#             */
/*   Updated: 2026/05/15 14:59:45 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
			return (printf("%d\n", i), false);
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
		exit(printf("Invalid color format"));
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit(printf("Invalid color value"));
	return (create_trgb(0, r, g, b));
}

bool	get_colors(t_map *map, char *line)
{
	if (!ft_strncmp(line, "F", 1))
		return (map->floor_color = parse_color(line + 1), true);
	else if (!ft_strncmp(line, "C", 1))
		return (map->ceiling_color = parse_color(line + 1), true);
	else
		return (printf("Error get_colors\n"), false);
}
