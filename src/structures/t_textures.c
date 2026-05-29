/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_textures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:51:05 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/29 13:57:04 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_textures	t_textures_new(void)
{
	t_textures	tex;
	
	tex.ceiling_color = 0;
	tex.floor_color = 0;
	tex.has_ceiling = false;
	tex.has_floor = false;
	tex.rdoor = t_tex_data_new();
	tex.ldoor = t_tex_data_new();
	tex.no = t_tex_data_new();
	tex.so = t_tex_data_new();
	tex.we = t_tex_data_new();
	tex.ea = t_tex_data_new();
	return (tex);
}

void	t_textures_free(void *mlx, t_textures *tex)
{
	t_tex_data_free(mlx, &tex->ea);
	t_tex_data_free(mlx, &tex->so); 
	t_tex_data_free(mlx, &tex->no);
	t_tex_data_free(mlx, &tex->we);
	t_tex_data_free(mlx, &tex->rdoor);
	t_tex_data_free(mlx, &tex->ldoor);
}