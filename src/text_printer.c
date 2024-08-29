/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:37:57 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/29 19:19:47 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_text(t_game *game)
{
	game->img->moves_text = mlx_put_string(game->mlx, "Moves: ",
			16, game->height * 64 - 44);
	mlx_image_to_window(game->mlx, game->img->fish_icon,
		108, game->height * 64 - 64);
	mlx_put_string(game->mlx, ": ", 160, game->height * 64 - 44);
}

void	print_eaten_fish(t_game *game)
{
	char	*str;

	str = ft_itoa(game->eaten);
	if (game->img->fish_counter)
		mlx_delete_image(game->img->fish_counter);
	game->img->fish_counter = mlx_put_string(game->mlx, str,
			190, game->height * 64 - 44);
	free(str);
}