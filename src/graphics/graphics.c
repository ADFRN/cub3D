/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:35:36 by afournie          #+#    #+#             */
/*   Updated: 2026/05/28 15:16:20 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_one_texture(t_game *game, t_img *tex, char *path)
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
	init_one_texture(game, &game->no_tex, game->map.no_txt);
	init_one_texture(game, &game->so_tex, game->map.so_txt);
	init_one_texture(game, &game->ea_tex, game->map.ea_txt);
	init_one_texture(game, &game->we_tex, game->map.we_txt);
	init_one_texture(game, &game->ldoor_tex, "./map/door_l.xpm");
	init_one_texture(game, &game->rdoor_tex, "./map/door_r.xpm");
	game->tile_size = game->no_tex.width;
}
