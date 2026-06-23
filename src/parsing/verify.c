/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:14:21 by afournie          #+#    #+#             */
/*   Updated: 2026/06/23 14:40:20 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	verify_texture_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

bool	is_valid_texture_path(t_textures *tex)
{
	if (!verify_texture_path(tex->no.tex_path))
		return (ft_putendl_fd("Error\nNO file not found", STDERR_FILENO),
			false);
	if (!verify_texture_path(tex->so.tex_path))
		return (ft_putendl_fd("Error\nSO file not found", STDERR_FILENO),
			false);
	if (!verify_texture_path(tex->ea.tex_path))
		return (ft_putendl_fd("Error\nEA file not found", STDERR_FILENO),
			false);
	if (!verify_texture_path(tex->we.tex_path))
		return (ft_putendl_fd("Error\nWE file not found", STDERR_FILENO),
			false);
	if (tex->has_door && !verify_texture_path(LDOOR_TEX))
		return (ft_putendl_fd("Error\nDOOR_L file not found", STDERR_FILENO),
			false);
	if (tex->has_door && !verify_texture_path(RDOOR_TEX))
		return (ft_putendl_fd("Error\nDOOR_R file not found", STDERR_FILENO),
			false);
	return (true);
}

static bool	texture_tester(t_game *game, char *path)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!img)
		return (false);
	else
		return (mlx_destroy_image(game->mlx, img), true);
}

bool	is_valid_texture(t_game *game)
{
	if (!is_valid_texture_path(&game->tex))
		return (false);
	if (!texture_tester(game, game->tex.no.tex_path))
		return (ft_putendl_fd("Error\nNO XPM file not working", STDERR_FILENO),
			false);
	if (!texture_tester(game, game->tex.so.tex_path))
		return (ft_putendl_fd("Error\nSO XPM file not working", STDERR_FILENO),
			false);
	if (!texture_tester(game, game->tex.ea.tex_path))
		return (ft_putendl_fd("Error\nEA XPM file not working", STDERR_FILENO),
			false);
	if (!texture_tester(game, game->tex.we.tex_path))
		return (ft_putendl_fd("Error\nWE XPM file not working", STDERR_FILENO),
			false);
	if (game->tex.has_door && !texture_tester(game, RDOOR_TEX))
		return (ft_putendl_fd("Error\nDOOR XPM file not working",
				STDERR_FILENO), false);
	if (game->tex.has_door && !texture_tester(game, LDOOR_TEX))
		return (ft_putendl_fd("Error\nDOOR XPM file not working",
				STDERR_FILENO), false);
	return (true);
}

bool	verify_all_data(t_map *map, t_textures *tex)
{
	if (!tex->has_ceiling || !tex->has_floor)
		return (ft_putendl_fd("Error\nmissing colors", STDERR_FILENO), false);
	if (!tex->no.has_tex || !tex->no.has_tex
		|| !tex->so.has_tex || !tex->we.has_tex)
		return (ft_putendl_fd("Error\nmissing textures", STDERR_FILENO), false);
	if (!check_map(map->map))
		return (false);
	return (true);
}
