/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_keys.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:52:47 by ttiprez           #+#    #+#             */
/*   Updated: 2026/05/12 15:44:04 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_keys	t_keys_new()
{
	t_keys keys;

	keys.w = false;
	keys.a = false;
	keys.s = false;
	keys.d = false;
	keys.left = false;
	keys.right = false;
	return (keys);
}