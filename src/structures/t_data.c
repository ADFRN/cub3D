/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:28:42 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/10 19:29:23 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_data	t_data_new(void	*mlx_ptr)
{
	t_data	data;

	data.img = mlx_new_image(mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.addr = mlx_get_data_addr(
		data.img,
		&data.bits_per_pixel,
		&data.line_length,
		&data.endian);
	return (data);
}
