/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:48:22 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/30 13:21:30 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_fish(t_game *game, int y, int x)
{
	int	i;

	i = 0;
	y = y * 64;
	x = x * 64;
	while (i < (int)game->img->fish->count)
	{
		if (game->img->fish->instances[i].x == x
			&& game->img->fish->instances[i].y == y)
			game->img->fish->instances[i].enabled = false;
		i++;
	}
}

t_game	*move_up(t_game *game)
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
			print_eaten_fish(game);
			game->grid[y - 1][x] = '0';
		}
		game->dolphin_y--;
		game->img->dolphin->instances[0].y -= PIXELS;
		game->moves++;
	}
	//check_game_status();
	return (game);
}

t_game	*move_down(t_game *game)
{
	size_t	y;
	size_t	x;

	y = game->dolphin_y;
	x = game->dolphin_x;
	if (game->grid[y + 1][x] != '1' && game->grid[y + 1][x] != 'E')
	{
		if (game->grid[y + 1][x] == 'C')
		{
			remove_fish(game, y + 1, x);
			game->eaten++;
			print_eaten_fish(game);
			game->grid[y + 1][x] = '0';
		}
		game->dolphin_y++;
		game->img->dolphin->instances[0].y += PIXELS;
		game->moves++;
	}
	//check_game_status();
	return (game);
}

t_game	*move_left(t_game *game)
{
	size_t	y;
	size_t	x;

	y = game->dolphin_y;
	x = game->dolphin_x;
	if (game->grid[y][x - 1] != '1' && game->grid[y][x - 1] != 'E')
	{
		if (game->grid[y][x - 1] == 'C')
		{
			remove_fish(game, y, x - 1);
			game->eaten++;
			print_eaten_fish(game);
			game->grid[y][x - 1] = '0';
		}
		game->dolphin_x--;
		game->img->dolphin->instances[0].x -= PIXELS;
		game->moves++;
	}
	//check_game_status();
	return (game);
}

t_game	*move_right(t_game *game)
{
	size_t	y;
	size_t	x;

	y = game->dolphin_y;
	x = game->dolphin_x;
	if (game->grid[y][x + 1] != '1' && game->grid[y][x + 1] != 'E')
	{
		if (game->grid[y][x + 1] == 'C')
		{
			remove_fish(game, y, x + 1);
			game->eaten++;
			print_eaten_fish(game);
			game->grid[y][x + 1] = '0';
		}
		game->dolphin_x++;
		game->img->dolphin->instances[0].x += PIXELS;
		game->moves++;
	}
	//check_game_status();
	return (game);
}
