/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:46:02 by jotrujil          #+#    #+#             */
/*   Updated: 2024/09/02 14:02:15 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_background(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (mlx_image_to_window(game->mlx, game->img->sand,
					x * PIXELS, y * PIXELS) < 0)
				error_msg("Error on image to windows when filling background");
			x++;
		}
		y++;
	}
}

static void	image_selector(t_game *game, size_t y, size_t x)
{
	if (game->grid[y][x] == '1')
	{
		if (mlx_image_to_window(game->mlx, game->img->coral,
				x * PIXELS, y * PIXELS) < 0)
			error_msg ("Error on image to windows when filling coral");
	}
	if (game->grid[y][x] == 'P')
	{
		if (mlx_image_to_window(game->mlx, game->img->dolphin,
				x * PIXELS, y * PIXELS) < 0)
			error_msg ("Error on image to windows when filling dolphin");
	}
	if (game->grid[y][x] == 'C')
	{
		if (mlx_image_to_window(game->mlx, game->img->fish,
				x * PIXELS, y * PIXELS) < 0)
			error_msg ("Error on image to windows when filling fish");
	}
	if (game->grid[y][x] == 'E')
	{
		if (mlx_image_to_window(game->mlx, game->img->exit_closed,
				x * PIXELS, y * PIXELS) < 0)
			error_msg ("Error on image to windows when filling exit");
	}
}

static void	spawn_enemies(t_game *game, size_t y, size_t x)
{
	if (game->grid[y][x] == 'X')
	{
		if (mlx_image_to_window(game->mlx, game->img->enemy,
				x * PIXELS, y * PIXELS) < 0)
			error_msg("Error on image to windows when filling enemies");
	}
}

void	render_map(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			image_selector(game, y, x);
			spawn_enemies(game, y, x);
			x++;
		}
		y++;
	}
	print_text(game);
}
