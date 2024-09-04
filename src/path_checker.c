/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:22:30 by jotrujil          #+#    #+#             */
/*   Updated: 2024/09/04 12:10:20 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(char **grid, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

static int	check_path(t_game *tmp_game, size_t y, size_t x)
{
	if (y >= tmp_game->height || x >= tmp_game->width)
		return (0);
	if (tmp_game->grid[y][x] == '1')
		return (0);
	if (tmp_game->grid[y][x] == 'C')
		tmp_game->fish--;
	if (tmp_game->grid[y][x] == 'E')
	{
		tmp_game->exit_x = 1;
		return (0);
	}
	tmp_game->grid[y][x] = '1';
	if (check_path(tmp_game, y + 1, x))
		return (1);
	if (check_path(tmp_game, y - 1, x))
		return (1);
	if (check_path(tmp_game, y, x + 1))
		return (1);
	if (check_path(tmp_game, y, x - 1))
		return (1);
	return (0);
}

void	flood_fill(t_game *game)
{
	t_game	tmp_game;
	size_t	i;

	tmp_game = (t_game)
	{
		.height = game->height,
		.width = game->width,
		.fish = game->fish,
		.dolphin_x = game->dolphin_x,
		.dolphin_y = game->dolphin_y,
		.exit_x = 0,
		.grid = (char **)malloc(game->height * sizeof(char *))
	};
	if (!tmp_game.grid)
		error_msg("Memory allocation failed for temporal grid");
	i = 0;
	while (i < tmp_game.height)
	{
		tmp_game.grid[i] = ft_strdup(game->grid[i]);
		i++;
	}
	check_path(&tmp_game, tmp_game.dolphin_y, tmp_game.dolphin_x);
	if (!(tmp_game.exit_x == 1 && tmp_game.fish == 0))
		error_msg("No valid path available. Please, review the map");
	free_grid(tmp_game.grid, tmp_game.height);
}
