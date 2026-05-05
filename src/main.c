/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:04:19 by afournie          #+#    #+#             */
/*   Updated: 2026/05/05 14:48:27 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	open_map(t_game *game, char *map)
{
	return ;
}

int	main(int ac, char **av)
{
	t_game	game;
	if (ac < 2)
		return (printf("2 arg required"), EXIT_FAILURE);
	open_map(&game, av[1]);
	return (EXIT_SUCCESS);
}
