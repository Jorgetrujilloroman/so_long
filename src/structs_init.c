/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:09:45 by jotrujil          #+#    #+#             */
/*   Updated: 2024/09/03 12:57:33 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*data_init(char *map)
{
	char	*map_str;
	char	**map_array;
	t_game	*data;

	map_str = read_map(map);
	map_empty_check(map_str);
	map_empty_lines_check(map_str);
	map_content_check(map_str);
	map_array = ft_split(map_str, '\n');
	map_shape_check(map_array);
	data = game_init(map_array);
	walls_check(data);
	flood_fill(data);
	free(map_str);
	return (data);
}

t_img	*img_init(mlx_t *mlx)
{
	t_img	*assets;

	assets = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!assets)
		return (NULL);
	assets = load_all_textures(mlx, assets);
	return (assets);
}

t_game	*game_init(char **grid)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		error_msg("Game struct memory allocation failed.");
	game->game_over = 0;
	game->grid = grid;
	game->width = ft_strlen(grid[0]);
	game->height = count_rows(grid);
	game->moves = 0;
	game->fish = count_fish(game);
	game->dolphin_x = get_element_pos(game, 'P', 'x');
	game->dolphin_y = get_element_pos(game, 'P', 'y');
	game->exit_x = get_element_pos(game, 'E', 'x');
	game->exit_y = get_element_pos(game, 'E', 'y');
	load_dolphin_textures(game);
	return (game);
}
