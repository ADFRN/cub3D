/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_draw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:45:02 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/01 17:38:07 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	t_draw_init(t_draw *d, double dist)
{
	d->line_height = (int)(WIN_HEIGHT / dist);
	d->draw_start = -d->line_height / 2 + WIN_HEIGHT / 2;
	if (d->draw_start < 0)
		d->draw_start = 0;
	d->draw_end = d->line_height / 2 + WIN_HEIGHT / 2;
	if (d->draw_end >= WIN_HEIGHT)
		d->draw_end = WIN_HEIGHT - 1;
}
