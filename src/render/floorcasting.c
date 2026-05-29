/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:06:28 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/29 18:38:14 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	floor_casting(t_game *g)
{
	for (int y = WIN_HEIGHT / 2; y < WIN_HEIGHT; y++)
	{
		int		p = y - WIN_HEIGHT / 2;
		float	pos_z = 0.5 * WIN_HEIGHT;
		float	row_distance = pos_z / p;

		float	ray_dir_x0 = g->player.dirx - g->player.planex;
		float	ray_dir_y0 = g->player.diry - g->player.planey;
		float	ray_dir_x1 = g->player.dirx + g->player.planex;
		float	ray_dir_y1 = g->player.diry + g->player.planey;
		float	floor_step_x = row_distance 
								* (ray_dir_x1 - ray_dir_x0) / WIN_WIDTH;
		float	floor_step_y = row_distance 
								* (ray_dir_y1 - ray_dir_y0) / WIN_WIDTH;
		float	floor_x = (g->player.posx / (WIN_WIDTH / g->map.width))				// coordonnees map
							+ row_distance * ray_dir_x0;
		float	floor_y = (g->player.posy / (WIN_HEIGHT / g->map.height)) 			// coordonnees map
							+ row_distance * ray_dir_y0;
		for (int x = 0; x < WIN_WIDTH; x++)
		{
			int	cell_x = (int)floor_x;
			int	cell_y = (int)floor_y;
			int	tx = (int)(g->tex.floor.tex.width * (floor_x - cell_x)) 
						& (g->tex.floor.tex.width - 1);
			int	ty = (int)(g->tex.floor.tex.height * (floor_y - cell_y)) 
						& (g->tex.floor.tex.height - 1);
			floor_x += floor_step_x;
			floor_y += floor_step_y;
			int	color = get_texture_pixel(&g->tex.floor.tex, tx, ty);
			ft_mlx_pixel_put(&g->data, x, y, color);
			color = get_texture_pixel(&g->tex.ceiling.tex, tx, ty);
			ft_mlx_pixel_put(&g->data, x, WIN_HEIGHT - y - 1, color);
		}
	}
}
