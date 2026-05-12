/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:04:19 by afournie          #+#    #+#             */
/*   Updated: 2026/05/11 14:04:03 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_cell(t_game *game, int x, int y, int color)
{
	int	cell_width;
	int	cell_height;
	int	i;
	int	j;

	cell_width = WIN_WIDTH / game->map.map_width;
	cell_height = WIN_HEIGHT / game->map.map_height;
	i = -1;
	while (++i < cell_height)
	{
		j = -1;
		while (++j < cell_width)
		{
			if (i == 0 || j == 0)
				ft_mlx_pixel_put(
					&game->data, 
					(x * cell_width + j), (y * cell_height + i), 0x00000000);
			else
				ft_mlx_pixel_put(
					&game->data, 
					(x * cell_width + j), (y * cell_height + i), color);
		}
	}
}

static void	fill_image(t_game *game, int ground_color, int wall_color)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				fill_cell(game, x, y, wall_color);
			else if (game->map.map[y][x] == '0')
				fill_cell(game, x, y, ground_color);
			else
				fill_cell(game, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

static void	draw_circle(t_game *game, int cx, int cy, int radius, int color)
{
	int	x;
	int	y;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				ft_mlx_pixel_put(&game->data, cx + x, cy + y, color);
			x++;
		}
		y++;
	}
}

static void	update_player_position(t_game *game)
{
	if (game->keys.w)
		game->player.posY -= 2;
	if (game->keys.s)
		game->player.posY += 2;
	if (game->keys.a)
		game->player.posX -= 2;
	if (game->keys.d)
		game->player.posX += 2;
}

static long	get_time_us(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

static int	render_next_frame(t_game *game)
{
	static long	last_frame = 0;
	long		now;

	now = get_time_us();
	if (now - last_frame < FRAME_TIME)
		return (0);
	last_frame = now;

	update_player_position(game);
	fill_image(game, 0x00FFFFFF, 0x0082C8E5);
	draw_circle(
		game, 
		game->player.posX, 
		game->player.posY, 
		game->player.radius, 
		0x00FF0000);
	mlx_put_image_to_window(game->mlx, game->win , game->data.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_game	game;
	
	char	**map = DEBUG_map();
	if (!map)
		return (EXIT_FAILURE);

	game = t_game_new(map);

	mlx_hook(game.win, 17, 0, (void *)clean_exit, &game);
	// mlx_hook(game.win, 6, (1L<<6), (void *)mouse_movement, &game);
	mlx_hook(game.win, 2, (1L<<0), (void *)key_press, &game);
	mlx_hook(game.win, 3, (1L<<1), (void *)key_release, &game);
	mlx_mouse_hook(game.win, mouse_click, &game);
	mlx_loop_hook(game.mlx, (void *)render_next_frame, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
