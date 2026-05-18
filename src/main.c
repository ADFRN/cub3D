/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:04:19 by afournie          #+#    #+#             */
/*   Updated: 2026/05/18 17:09:52 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	if(ac != 2)
		return (1);
	game = t_game_new(av[1]);
	// mlx_hook(game.win, 17, 0, (void *)clean_exit, &game);
	// mlx_hook(game.win, 6, (1L<<6), (void *)mouse_movement, &game);
	// mlx_hook(game.win, 2, (1L<<0), (void *)key_press, &game);
	// mlx_hook(game.win, 3, (1L<<1), (void *)key_release, &game);
	// mlx_mouse_hook(game.win, mouse_click, &game);
	// mlx_loop_hook(game.mlx, (void *)render_next_frame, &game);
	// mlx_loop(game.mlx);

	printf("map.no_txt: %s\n", game.map.no_txt);
	printf("map.so_txt: %s\n", game.map.so_txt);
	printf("map.ea_txt: %s\n", game.map.ea_txt);
	printf("map.we_txt: %s\n", game.map.we_txt);
	printf("map.floor: 0x%08X\n", game.map.floor_color);
	printf("map.ceiling: 0x%08X\n", game.map.ceiling_color);
	for (int y = 0; y < game.map.height; y++)
		printf("%s", game.map.map[y]);
	return (EXIT_SUCCESS);
}
