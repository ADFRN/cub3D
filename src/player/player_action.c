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

// TMP TMP TMP TMP TMP TMP
static void	revert_door_states(t_door *doors)
{
	int	i;

	i = -1;
	while (++i < doors[0].nb_doors)
		if (!ft_strcmp(doors[i].state, CLOSE))
			doors[i].state = OPEN;
		else if (!ft_strcmp(doors[i].state, OPEN))
			doors[i].state = CLOSE;
}

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
	else if (key == E_KEY)
		revert_door_states(game->map.doors);
	else if (key == LEFT_KEY)
		game->keys.left = true;
	else if (key == RIGHT_KEY)
		game->keys.right = true;
	else if (key == SHIFT_KEY)
		game->keys.shift = true;
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
	else if (key == SHIFT_KEY)
		game->keys.shift = false;
	return (1);
}
