/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:00:20 by afournie          #+#    #+#             */
/*   Updated: 2026/06/23 15:00:20 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	validation_failed_exit(t_game *game, t_map *map)
{
	t_textures_free(game->mlx, &game->tex);
	t_map_free(map);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(EXIT_FAILURE);
}

int	clean_exit(t_game *game)
{
	t_textures_free(game->mlx, &game->tex);
	t_map_free(&game->map);
	if (game->data.img)
		mlx_destroy_image(game->mlx, game->data.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

long	get_time_us(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

bool	is_valid_case(t_door *door, char c)
{
	return (c == FLOOR || c == WEST_SPAWN || c == NORTH_SPAWN
		|| c == SOUTH_SPAWN || c == EST_SPAWN || (c == DOOR
			&& door->state == DOOR_OPEN));
}
