/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:15:40 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/22 15:30:34 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (i != 3 || ft_isdigit(split[i - 1]) == '\n')
		exit((ft_putendl_fd("error: invalid color format", STDERR_FILENO), 
			EXIT_FAILURE));
}