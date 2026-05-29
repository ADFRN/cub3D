/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:35:36 by afournie          #+#    #+#             */
/*   Updated: 2026/05/29 13:29:29 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	load_texture(t_game *game, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->width,
			&tex->height);
	if (!tex->img)
		return ;
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len,
			&tex->endian);
}

void	init_textures(t_game *game)
{
	load_texture(game, &game->no_tex, game->tex.no.tex_path);
	load_texture(game, &game->so_tex, game->tex.so.tex_path);
	load_texture(game, &game->ea_tex, game->tex.ea.tex_path);
	load_texture(game, &game->we_tex, game->tex.we.tex_path);
	load_texture(game, &game->ldoor_tex, "./map/door_l.xpm");
	load_texture(game, &game->rdoor_tex, "./map/door_r.xpm");
	game->tile_size = game->no_tex.width;
}
