/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:46:53 by jotrujil          #+#    #+#             */
/*   Updated: 2024/09/04 11:31:50 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_all_enemies(t_game *game, size_t enemy_index)
{
	t_enemy_move	enemy_move;

	enemy_move.x = &game->img->enemy->instances[enemy_index].x;
	enemy_move.y = &game->img->enemy->instances[enemy_index].y;
	enemy_move.ran_x = (rand() % 3 - 1) * PIXELS;
	enemy_move.ran_y = (rand() % 3 - 1) * PIXELS;
	if (enemy_move.ran_x == 0 && enemy_move.ran_y == 0)
		return ;
	enemy_move.index_x = *enemy_move.x + enemy_move.ran_x;
	enemy_move.index_y = *enemy_move.y + enemy_move.ran_y;
	if (enemy_move.index_x != 0)
		enemy_move.index_x /= PIXELS;
	if (enemy_move.index_y != 0)
		enemy_move.index_y /= PIXELS;
	if (game->grid[enemy_move.index_y][enemy_move.index_x] != '1' &&
	game->grid[enemy_move.index_y][enemy_move.index_x] != 'C' &&
	game->grid[enemy_move.index_y][enemy_move.index_x] != 'E' &&
	game->grid[enemy_move.index_y][enemy_move.index_x] != 'X')
	{
		*enemy_move.x += enemy_move.ran_x;
		*enemy_move.y += enemy_move.ran_y;
	}
}

static void	check_enemies_status(t_game	*game)
{
	size_t	enemy_index;

	enemy_index = 0;
	while (enemy_index < game->img->enemy->count)
	{
		if (game->dolphin_x * PIXELS
			== (size_t)game->img->enemy->instances[enemy_index].x
			&& game->dolphin_y * PIXELS
			== (size_t)game->img->enemy->instances[enemy_index].y)
		{
			if (!game->game_over)
			{
				game->game_over = 1;
				win_lose_display(game, 'l');
				ft_printf("😱 Oh, noooou!! 😱\n");
				ft_printf("💀 You were killed by the evil Arlong !! 💀\n");
				ft_printf("🔁Try again to defeat him and eat all the fish!🔁\n");
				mlx_loop_hook(game->mlx,
					(void (*)(void *))close_window_after_delay, game);
			}
			break ;
		}
		enemy_index++;
	}
}

void	enemy_patrol(void *temp_game)
{
	t_game			*game;
	size_t			enemy_index;
	static size_t	freq_move_counter;

	if (!temp_game)
		return ;
	game = (t_game *)temp_game;
	enemy_index = 0;
	check_enemies_status(game);
	if (freq_move_counter++ < 150)
		return ;
	while (enemy_index < game->img->enemy->count)
	{
		move_all_enemies(game, enemy_index);
		enemy_index++;
	}
	freq_move_counter = 0;
}
