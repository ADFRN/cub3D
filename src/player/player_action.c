/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 18:15:41 by marvin            #+#    #+#             */
/*   Updated: 2026/05/10 18:15:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press(int key, t_game *game)
{
	if (key == ESC_KEY)
		clean_exit(game);
	else if (key == W_KEY)
		game->keys.w = true;
	else if (key == S_KEY)
		game->keys.s = true;
	else if (key == A_KEY)
		game->keys.a = true;
	else if (key == D_KEY)
		game->keys.d = true;
	else if (key == LEFT_KEY)
		game->keys.left = true;
	else if (key == RIGHT_KEY)
		game->keys.right = true;
	return (1);
}

int	key_release(int key, t_game *game)
{
	if (key == W_KEY)
		game->keys.w = false;
	else if (key == S_KEY)
		game->keys.s = false;
	else if (key == A_KEY)
		game->keys.a = false;
	else if (key == D_KEY)
		game->keys.d = false;
	else if (key == LEFT_KEY)
		game->keys.left = false;
	else if (key == RIGHT_KEY)
		game->keys.right = false;
	return (1);
}