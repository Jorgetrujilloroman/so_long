/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:48:22 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/29 19:29:52 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_fish(t_game *game, size_t y, size_t x)
{
	size_t	i;

	i = 0;
	y = y * 64;
	x = x * 64;
	while (i < game->img->fish->count)
	{
		if (game->img->fish->instances[i].x == x
			&& game->img->fish->instances[i].y == y)
			game->img->fish->instances[i].enabled = false;
		i++;
	}
}

void	move_up(t_game *game)
{
	size_t	y;
	size_t	x;

	y = game->dolphin_y;
	x = game->dolphin_x;
	if (game->grid[y - 1][x] != '1' && game->grid[y - 1][x] != 'E')
	{
		if (game->grid[y - 1][x] == 'C')
		{
			remove_fish(game, y - 1, x);
			game->eaten++;
			print_fish(game);
			game->grid[y - 1][x] = '0';
		}
		game->dolphin_y--;
		game->img->dolphin->instances[0].y -= PIXELS;
		game->moves++;
	}
	//TODO
}
