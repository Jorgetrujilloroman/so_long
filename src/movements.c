/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:15:03 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/29 14:39:01 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, char axis, char dir)
{
	if (axis == 'y')
	{
		if (dir == 'u')
			move_up();
		if (dir == 'd')
			move_down();
	}
	if (axis == 'x')
	{
		if (dir == 'l')
			move_left();
		if (dir == 'r')
			move_right();
	}
	load_dolphin();
}

void	move_hook(mlx_key_data_t key_data, void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS)
		move_player(game, 'y', 'u');
}
