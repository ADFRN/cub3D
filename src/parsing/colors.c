/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:56:09 by afournie          #+#    #+#             */
/*   Updated: 2026/06/23 15:24:39 by afournie         ###   ########.fr       */
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

static bool	parse_color(char *line, int *res)
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
	if (!check_split(colors))
		return (false);
	if (!is_valid_number(colors[0]) || !is_valid_number(colors[1])
		|| !is_valid_number(colors[2]) || colors[3] != NULL)
		return ((free_split(colors),
				ft_putendl_fd("Error\ninvalid color format", STDERR_FILENO),
				false));
	free((r = ft_atoi(colors[0]), g = ft_atoi(colors[1]),
			b = ft_atoi(colors[2]), free_split(colors), NULL));
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return ((ft_putendl_fd("Error\ninvalid color value", STDERR_FILENO),
				false));
	*res = create_trgb(0, r, g, b);
	return (true);
}

bool	get_colors(t_textures *tex, char *line)
{
	if (!ft_strncmp(line, "F", 1))
	{
		if (tex->has_floor)
			return (ft_putendl_fd("Error\nfloor color already set",
					STDERR_FILENO), false);
		if (!parse_color(line + 1, &tex->floor_color))
			return (false);
		return (tex->has_floor = 1, true);
	}
	else if (!ft_strncmp(line, "C", 1))
	{
		if (tex->has_ceiling)
			return (ft_putendl_fd("Error\nceiling color already set",
					STDERR_FILENO), false);
		if (!parse_color(line + 1, &tex->ceiling_color))
			return (false);
		return (tex->has_ceiling = 1, true);
	}
	return (ft_putendl_fd("Error\ncolors missing", STDERR_FILENO), false);
}
