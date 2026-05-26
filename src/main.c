/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:04:19 by afournie          #+#    #+#             */
/*   Updated: 2026/05/26 11:46:44 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(void)
{
	t_game	game;
	char	**map;

	map = debug_map();
	if (!map)
		return (EXIT_FAILURE);
	game = t_game_new(map);
	debug_print_t_door(game.map.doors, game.map.nb_doors);
	mlx_hook(game.win, 17, 0, (void *)clean_exit, &game);
	mlx_hook(game.win, 6, (1L << 6), (void *)mouse_movement, &game);
	mlx_hook(game.win, 2, (1L << 0), (void *)key_press, &game);
	mlx_hook(game.win, 3, (1L << 1), (void *)key_release, &game);
	mlx_mouse_hook(game.win, (void *)mouse_click, &game);
	mlx_loop_hook(game.mlx, (void *)render_next_frame, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
