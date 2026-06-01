/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:52:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/01 16:32:34 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_texture(t_draw *d, t_ray *ray, t_img *tex)
{
	if (ray->side == 0)
		d->wall_x = ray->posy + get_perp_wall_dist(ray) * ray->diry;
	else
		d->wall_x = ray->posx + get_perp_wall_dist(ray) * ray->dirx;
	d->wall_x -= floor(d->wall_x);
	d->tex_x = (int)(d->wall_x * (double)tex->width);
	if ((ray->side == 0 && ray->dirx > 0) || (ray->side == 1 && ray->diry < 0))
		d->tex_x = tex->width - d->tex_x - 1;
	d->step = (double)tex->height / (double)d->line_height;
	d->tex_pos = (d->draw_start - WIN_HEIGHT / 2 + d->line_height / 2)
		* d->step;
}

static double	draw_column(t_game *game, t_ray *ray, int x)
{
	t_draw	d;
	t_img	*tex;
	double	perp_wall_dist;
	int		tex_y;

	perp_wall_dist = get_perp_wall_dist(ray);
	t_draw_init(&d, perp_wall_dist);
	tex = get_wall_texture(game, ray);
	init_texture(&d, ray, tex);
	d.y = d.draw_start;
	while (d.y < d.draw_end)
	{
		tex_y = (int)d.tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		d.tex_pos += d.step;
		d.color = get_texture_pixel(tex, d.tex_x, tex_y);
		ft_mlx_pixel_put(&game->data, x, d.y, d.color);
		d.y++;
	}
	return (perp_wall_dist);
}

void	raycast(t_game *game)
{
	int	x;

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
		if (r->mapx < 0 || r->mapy < 0
			|| r->mapx >= map->width || r->mapy >= map->height)
		{
			r->hit = true;
			continue ;
		}
		if (map->map[r->mapy][r->mapx] == WALL
			|| t_door_get(map->doors, r->mapx, r->mapy)->state == DOOR_CLOSE)
			r->hit = true;
	}
}
