/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:21:45 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/15 17:24:09 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_game	t_game_new(char *map_path)
{
	t_game	game;
	t_map	map;

	map = init_map();
	if (!get_map_info(&map, map_path))
		exit(1);
	game.map = map;
	game.mlx = mlx_init();
	if (!is_valid_texture(&game))
		exit(1);
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	game.last_frame = 0;
	game.keys = t_keys_new();
	game.player = t_player_new();
	game.data = t_data_new(game.mlx);
	return (game);
}
