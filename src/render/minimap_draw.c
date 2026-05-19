/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:27:15 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/19 10:46:59 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_ray(t_game *game, t_player *player, int x, int range)
{
	int	i;
	int	px;
	int	py;

	player->camerax = 2.0 * x / (double)WIN_WIDTH - 1.0;
	player->raydir_x = player->dirx + player->planex * player->camerax;
	player->raydir_y = player->diry + player->planey * player->camerax;
	i = 0;
	while (i < range)
	{
		px = game->minimap.p_posx + (int)(player->raydir_x * i);
		py = game->minimap.p_posy + (int)(player->raydir_y * i);
		if (px < 0 || px >= WIN_WIDTH || py < 0 || py >= WIN_HEIGHT)
			break ;
		ft_mlx_pixel_put(&game->data, px, py, RED);
		i++;
	}
}

void	draw_player(t_game *game, int cx, int cy, int color)
{
	int	x;
	int	y;
	int	radius;

	radius = (ATH_SIZE / 100 * 2);
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius && cx < WIN_WIDTH
				&& cy < WIN_HEIGHT && cy + y > 0)
				ft_mlx_pixel_put(&game->data, cx + x, cy + y, color);
			x++;
		}
		y++;
	}
}

static double	get_wall_dist(t_ray *ray)
{
	double	perp_wall_dist;

	if (ray->side == 0)
		perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	return (perp_wall_dist);
}

void	draw_raycast(t_game *game)
{
	int		x;
	int		cell_size;
	t_ray	ray;

	ray = t_ray_new();
	cell_size = game->minimap.cell_size;
	x = 0;
	while (x < WIN_WIDTH)
	{
		t_ray_update(game, &ray, x);
		init_step(&ray);
		dda_loop(game, &ray);
		draw_ray(game, &game->player, x, get_wall_dist(&ray) * cell_size);
		x++;
	}
}
