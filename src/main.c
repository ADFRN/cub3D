/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:04:19 by afournie          #+#    #+#             */
/*   Updated: 2026/05/26 16:49:01 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (EXIT_FAILURE);
	game = t_game_new(av[1]);
	mlx_hook(game.win, 17, 0, (void *)clean_exit, &game);
	mlx_hook(game.win, 6, (1L << 6), (void *)mouse_movement, &game);
	mlx_hook(game.win, 2, (1L << 0), (void *)key_press, &game);
	mlx_hook(game.win, 3, (1L << 1), (void *)key_release, &game);
	mlx_mouse_hook(game.win, (void *)mouse_click, &game);
	mlx_loop_hook(game.mlx, (void *)render_next_frame, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
