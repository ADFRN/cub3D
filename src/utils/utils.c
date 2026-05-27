/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 18:18:51 by marvin            #+#    #+#             */
/*   Updated: 2026/05/10 18:18:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	clean_exit(t_game *game)
{
	if (game->data.img)
		mlx_destroy_image(game->mlx, game->data.img);
	if (game->no_tex.img)
		mlx_destroy_image(game->mlx, game->no_tex.img);
	if (game->so_tex.img)
		mlx_destroy_image(game->mlx, game->so_tex.img);
	if (game->ea_tex.img)
		mlx_destroy_image(game->mlx, game->ea_tex.img);
	if (game->we_tex.img)
		mlx_destroy_image(game->mlx, game->we_tex.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	t_map_free(&game->map);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	printf("exit\n");
	exit(EXIT_SUCCESS);
	return (0);
}

long	get_time_us(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}
