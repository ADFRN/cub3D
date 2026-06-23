/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:21:45 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/23 15:17:05 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_game	t_game_new(char *map_path)
{
	t_game	game;

	game.mlx = mlx_init();
	game.last_frame = 0;
	game.mouse_warping = false;
	game.tex = t_textures_new();
	game.map = t_map_new(&game, map_path);
	if (!is_valid_texture_path(&game.tex) || !is_valid_texture(&game))
		validation_failed_exit(&game, &game.map);
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	game.player = t_player_new(game);
	game.ray = t_ray_new();
	game.minimap = t_minimap_new(game.map, game.ray);
	game.player = t_player_new(game);
	game.keys = t_keys_new();
	game.data = t_data_new(game.mlx);
	init_textures(&game);
	return (game);
}
