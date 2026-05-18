/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:14:21 by afournie          #+#    #+#             */
/*   Updated: 2026/05/18 17:01:14 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"

bool	is_valid_texture_path(t_game *game)
{
	int	fd;

	fd = open(game->map.no_txt, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error\nNO file not found", STDERR_FILENO),
			false);
	close(fd);
	fd = open(game->map.so_txt, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error\nSO file not found", STDERR_FILENO),
			false);
	close(fd);
	fd = open(game->map.ea_txt, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error\nEA file not found", STDERR_FILENO),
			false);
	close(fd);
	fd = open(game->map.we_txt, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error\nWE file not found", STDERR_FILENO),
			false);
	close(fd);
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
	if (!is_valid_texture_path(game))
		return (false);
	if (!texture_tester(game, game->map.no_txt))
		return (ft_putendl_fd("Error\nNO XPM file not working", STDERR_FILENO),
			false);
	if (!texture_tester(game, game->map.so_txt))
		return (ft_putendl_fd("Error\nSO XPM file not working", STDERR_FILENO),
			false);
	if (!texture_tester(game, game->map.ea_txt))
		return (ft_putendl_fd("Error\nEA XPM file not working", STDERR_FILENO),
			false);
	if (!texture_tester(game, game->map.we_txt))
		return (ft_putendl_fd("Error\nWE XPM file not working", STDERR_FILENO),
			false);
	return (true);
}

bool	verify_all_data(t_map *map)
{
	if (!map->has_ceiling || !map->has_floor)
		return (ft_putendl_fd("Error\nMissing colors", STDERR_FILENO), false);
	if (!map->has_no || !map->has_ea || !map->has_so || !map->has_we)
		return (ft_putendl_fd("Error\nMissing textures", STDERR_FILENO), false);
	// if (!check_map(map->map))
	// 	return (ft_putendl_fd("Error\nMap problem", STDERR_FILENO), false);
	return (true);
}
