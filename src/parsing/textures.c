/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:56:06 by afournie          #+#    #+#             */
/*   Updated: 2026/07/06 12:47:30 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	trim_texture(char **tex, char *set)
{
	char	*tmp;

	if (!tex || !*tex)
		return ;
	tmp = ft_strtrim(*tex, set);
	free(*tex);
	*tex = tmp;
}

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
		exit(EXIT_FAILURE);
	while (path[i] && path[i] != '\n')
	{
		tmp[y] = path[i];
		y++;
		i++;
	}
	tmp[y] = '\0';
	return (tmp);
}

static bool	textures_ns(t_textures *t, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
	{
		if (t->no.has_tex)
			return (ft_putendl_fd("Error\nNO textures already set",
					STDERR_FILENO), false);
		t->no.tex_path = cpy_textures(line);
		trim_texture(&t->no.tex_path, " \t\n");
		if (!t->no.tex_path)
			return (false);
		return (t->no.has_tex = true, true);
	}
	else
	{
		if (t->so.has_tex)
			return (ft_putendl_fd("Error\nSO textures already set",
					STDERR_FILENO), false);
		t->so.tex_path = cpy_textures(line);
		trim_texture(&t->so.tex_path, " \t\n");
		if (!t->so.tex_path)
			return (false);
		return (t->so.has_tex = true, true);
	}
}

static bool	textures_we(t_textures *t, char *line)
{
	if (!ft_strncmp(line, "WE", 2))
	{
		if (t->we.has_tex)
			return (ft_putendl_fd("Error\nWE textures already set",
					STDERR_FILENO), false);
		t->we.tex_path = cpy_textures(line);
		trim_texture(&t->we.tex_path, " \t\n");
		if (!t->we.tex_path)
			return (false);
		return (t->we.has_tex = true, true);
	}
	else
	{
		if (t->ea.has_tex)
			return (ft_putendl_fd("Error\nEA textures already set",
					STDERR_FILENO), false);
		t->ea.tex_path = cpy_textures(line);
		trim_texture(&t->ea.tex_path, " \t\n");
		if (!t->ea.tex_path)
			return (false);
		return (t->ea.has_tex = true, true);
	}
}

bool	get_textures(t_textures *tex, char *line)
{
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2))
		return (textures_ns(tex, line));
	else if (!ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		return (textures_we(tex, line));
	return (ft_putendl_fd("Error\nan error was encountered with the textures",
			STDERR_FILENO), false);
}
