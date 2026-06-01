/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tex_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:52:09 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/01 17:37:51 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_tex_data	t_tex_data_new(void)
{
	t_tex_data	tex_data;

	tex_data.tex_path = NULL;
	tex_data.has_tex = false;
	tex_data.tex = t_img_new();
	return (tex_data);
}

void	t_tex_data_free(void *mlx, t_tex_data *tex_data)
{
	if (tex_data->tex_path)
		free(tex_data->tex_path);
	t_img_free(mlx, &tex_data->tex);
}
