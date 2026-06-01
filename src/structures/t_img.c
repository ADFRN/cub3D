/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_img.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:55:17 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/01 17:37:56 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_img	t_img_new(void)
{
	t_img	img;

	img.img = NULL;
	img.addr = NULL;
	img.bpp = 0;
	img.line_len = 0;
	img.endian = 0;
	img.width = 0;
	img.height = 0;
	return (img);
}

void	t_img_free(void *mlx, t_img *img)
{
	if (img->img)
		mlx_destroy_image(mlx, img->img);
}
