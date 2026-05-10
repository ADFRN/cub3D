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
		game->keys.w = 1;
	else if (key == S_KEY)
		game->keys.s = 1;
	else if (key == A_KEY)
		game->keys.a = 1;
	else if (key == D_KEY)
		game->keys.d = 1;
	return (1);
}

int	key_release(int key, t_game *game)
{
	if (key == W_KEY)
		game->keys.w = 0;
	else if (key == S_KEY)
		game->keys.s = 0;
	else if (key == A_KEY)
		game->keys.a = 0;
	else if (key == D_KEY)
		game->keys.d = 0;
	return (1);
}