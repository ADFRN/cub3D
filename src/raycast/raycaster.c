/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:52:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/26 12:18:03 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static double	draw_column(t_game *game, t_ray *ray, int x)
{
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		y;

	if (ray->side == 0)
		perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	line_height = (int)(WIN_HEIGHT / perp_wall_dist);
	draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	y = draw_start;
	while (y < draw_end)
	{
		ft_mlx_pixel_put(&game->data, x, y, GREY);
		y++;
	}
	return (perp_wall_dist);
}

void	raycast(t_game *game)
{
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		t_ray_update(game, &game->ray, x);
		init_step(&game->ray);
		dda_loop(game, &game->ray);
		draw_column(game, &game->ray, x);
		x++;
	}
}

void	init_step(t_ray *ray)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->side_dist_x = (ray->posx - ray->mapx) * ray->delta_dist_x;
	}
	else
	{
		ray->stepx = 1;
		ray->side_dist_x = (ray->mapx + 1.0 - ray->posx) * ray->delta_dist_x;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->side_dist_y = (ray->posy - ray->mapy) * ray->delta_dist_y;
	}
	else
	{
		ray->stepy = 1;
		ray->side_dist_y = (ray->mapy + 1.0 - ray->posy) * ray->delta_dist_y;
	}
}

void	dda_loop(t_game *game, t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (ray->mapx < 0 || ray->mapy < 0
			|| ray->mapx >= game->map.width
			|| ray->mapy >= game->map.height)
		{
			ray->hit = true;
			continue ;
		}
		if (game->map.map[ray->mapy][ray->mapx] == WALL
			|| is_open(t_door_get(game->map.doors, ray->mapx, ray->mapy)))
			ray->hit = true;
	}
}
