/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:15:40 by ttiprez           #+#    #+#             */
/*   Updated: 2026/07/01 14:22:53 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_split(char **split)
{
	int		i;
	char	*tmp;

	i = 0;
	while (split[i])
		i++;
	if (i != 3 || !ft_strcmp(split[i - 1], "\n"))
		return ((ft_putendl_fd("Error\ninvalid color format", STDERR_FILENO),
				false));
	i = -1;
	while (split[++i])
	{
		tmp = ft_strtrim(split[i], " \t\n");
		free(split[i]);
		split[i] = tmp;
	}
	return (true);
}
