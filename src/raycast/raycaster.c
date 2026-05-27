/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:52:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/27 13:14:36 by afournie         ###   ########.fr       */
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
	init_draw(&d, perp_wall_dist);
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
		if (ray->mapx < 0 || ray->mapy < 0 || ray->mapx >= game->map.width
			|| ray->mapy >= game->map.height)
		{
			ray->hit = true;
			continue ;
		}
		if (game->map.map[ray->mapy][ray->mapx] == '1')
			ray->hit = true;
	}
}
