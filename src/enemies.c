/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:46:53 by jotrujil          #+#    #+#             */
/*   Updated: 2024/09/03 17:22:47 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	t_game	*game;
	size_t	enemy_index;
	size_t	move_counter;

	if (!temp_game)
		return ;
	game = (t_game *)temp_game;
	enemy_index = 0;
	check_enemies_status(game);
	if (move_counter < 30)
		return ;
	while (enemy_index < game->img->enemy->count)
	{
		//move_all_enemies(game, enemy_index);
		enemy_index++;
	}
	move_counter = 0;
}
