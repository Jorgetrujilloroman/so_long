/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:15:03 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/30 13:12:40 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	load_dolphin(t_game *game, char dir)
{
	if (dir == 'u')
		mlx_texture_to_image
} */

static void	move_player(t_game *game, char axis, char dir)
{
	//load_dolphin(game, dir);
	if (axis == 'y')
	{
		if (dir == 'u')
			move_up(game);
		if (dir == 'd')
			move_down(game);
	}
	if (axis == 'x')
	{
		if (dir == 'l')
			move_left(game);
		if (dir == 'r')
			move_right(game);
	}
}

void	move_hook(mlx_key_data_t key_data, void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if ((key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP)
		&& key_data.action == MLX_PRESS)
		move_player(game, 'y', 'u');
	if ((key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT)
		&& key_data.action == MLX_PRESS)
		move_player(game, 'x', 'l');
	if ((key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN)
		&& key_data.action == MLX_PRESS)
		move_player(game, 'y', 'd');
	if ((key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT)
		&& key_data.action == MLX_PRESS)
		move_player(game, 'x', 'r');
}
