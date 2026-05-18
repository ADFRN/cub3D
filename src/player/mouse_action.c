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

int	mouse_click(int button, int x, int y, void *param)
{
	(void)param;
	printf("button = %d\nx = %d | y = %d\n", button, x, y);
	return (0);
}

int	mouse_movement(int x, int y, void *param)
{
	(void)param;
	printf("mouse_coordonnee :\nx = %d | y = %d\n", x, y);
	return (0);
}
