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
	(void)start_y;
	mouse_move(WIN_WIDTH / 2, WIN_HEIGHT / 2, game);
	rotate_player(&game->player, (start_x - WIN_WIDTH / 2) * M_ROT_SPEED);
	return (0);
}
