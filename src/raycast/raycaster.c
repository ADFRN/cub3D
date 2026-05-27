/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:52:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/27 13:34:08 by ttiprez          ###   ########.fr       */
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
		dda_loop(&game->map, &game->ray);
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

void	dda_loop(t_map *map, t_ray *r)
{
	while (!r->hit)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			free((r->mapx += r->stepx, r->side = 0, NULL));
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			free((r->mapy += r->stepy, r->side = 1, NULL));
		}
		if (r->mapx < 0 || r->mapy < 0 || r->mapx >= map->width
			|| r->mapy >= map->height)
		{
			r->hit = true;
			continue ;
		}
		if (map->map[r->mapy][r->mapx] == WALL
			|| t_door_get(map->doors, r->mapx, r->mapy)->state == DOOR_CLOSE)
			r->hit = true;
	}
}
