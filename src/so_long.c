/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:31:06 by jotrujil          #+#    #+#             */
/*   Updated: 2024/09/04 12:53:37 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_img	*images;

	if (argc != 2)
		error_msg("Please, use one .ber map file as argument ¬¬'");
	check_file_format(argv[1]);
	game = data_init(argv[1]);
	game->mlx = mlx_init(game->width * PIXELS, game->height * PIXELS,
			"so_long", false);
	if (!game->mlx)
		return (EXIT_FAILURE);
	images = img_init(game->mlx);
	if (!images)
		error_msg("Failed to initialite images");
	game->img = images;
	fill_background(game);
	render_map(game);
	mlx_key_hook(game->mlx, move_hook, game);
	mlx_loop_hook(game->mlx, enemy_patrol, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_game(game);
	game = NULL;
	return (EXIT_SUCCESS);
}
