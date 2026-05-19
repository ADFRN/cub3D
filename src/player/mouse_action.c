/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 18:15:48 by marvin            #+#    #+#             */
/*   Updated: 2026/05/10 18:15:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_click(int button, int x, int y, t_game *game)
{
	(void)game;
	printf("button = %d\nx = %d | y = %d\n", button, x, y);
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{	
	(void)x;
	(void)y;
	if (game->mouse_warping)
		return (game->mouse_warping = false, 0);
	game->mouse_warping = true;
	mlx_mouse_move(game->mlx, game->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}

int	mouse_movement(int start_x, int start_y, t_game *game)
{
	int	x;
	int	y;

	(void)start_x;
	(void)start_y;
	mlx_mouse_get_pos(game->mlx, game->win, &x, &y);
	if (x <= WIN_WIDTH / 3 * 1)
		mouse_move(WIN_WIDTH / 3 * 2, 0, game);
	if (x >= WIN_WIDTH / 3 * 2)
		mouse_move(WIN_WIDTH / 3 * 1, 0, game);
	int delta_x = x - WIN_WIDTH / 2;
	rotate_player(&game->player, delta_x * 0.0003);
	return (0);
}
