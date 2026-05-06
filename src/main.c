/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:04:19 by afournie          #+#    #+#             */
/*   Updated: 2026/05/06 18:31:18 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_data	data;
}	t_game;

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	player_action(int key, void *param)
{
	(void)param;
	printf("key = %d\n", key);
	return (1);
}

int	mouse_click(int button, int x, int y, void *param)
{
	(void)param;
	printf("button = %d\nx = %d | y = %d\n", button, x, y);
	return (0);
}

int	mouse_movement(int x, int y, void *param)
{
	(void)param;
	printf("mouse_coordonnee :\nx = %d | y = %d\n", x, y);
	return (0);
}

int	clean_exit(t_game *game)
{
	mlx_destroy_image(game->mlx, game->data.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	printf("exit\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 500, 500, "Cub3D");
	game.data.img = mlx_new_image(game.mlx, 500, 500);
	game.data.addr = mlx_get_data_addr(game.data.img, &game.data.bits_per_pixel,
		&game.data.line_length, &game.data.endian);
	ft_mlx_pixel_put(&game.data, 250, 250, 0x00FF0000);
	mlx_put_image_to_window(game.mlx, game.win , game.data.img, 0, 0);
	mlx_hook(game.win, 17, 0, (void *)clean_exit, &game);
	mlx_hook(game.win, 6, (1L<<6), (void *)mouse_movement, &game);
	mlx_key_hook(game.win, player_action, NULL);
	mlx_mouse_hook(game.win, mouse_click, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
