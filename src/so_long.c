/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:31:06 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/23 10:48:58 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error_msg("Please, use one .ber map file as argument ¬¬'");
	check_file_format(argv[1]);
	game = data_init(argv[1]);
	/* game->mlx = mlx_init(game->width * PIXELS, game->height * PIXELS,
			"so_long", false); */
}
