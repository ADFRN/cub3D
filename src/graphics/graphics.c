/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:35:36 by afournie          #+#    #+#             */
/*   Updated: 2026/05/28 17:36:33 by ttiprez          ###   ########.fr       */
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
	load_texture(game, &game->no_tex, game->map.no_txt);
	load_texture(game, &game->so_tex, game->map.so_txt);
	load_texture(game, &game->ea_tex, game->map.ea_txt);
	load_texture(game, &game->we_tex, game->map.we_txt);
	load_texture(game, &game->ldoor_tex, "./map/door_l.xpm");
	load_texture(game, &game->rdoor_tex, "./map/door_r.xpm");
	game->tile_size = game->no_tex.width;
}
