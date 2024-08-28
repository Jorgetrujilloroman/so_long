/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:05:42 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/28 13:30:09 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walls_check(t_game	*game)
{
	size_t	i;

	i = 0;
	while (game->grid[0][i])
	{
		if (game->grid[0][i] != '1' || game->grid[game->height - 1][i] != '1')
			error_msg("The map is not properly bounded with walls");
		i++;
	}
	i = 0;
	while (game->grid[i])
	{
		if (game->grid[i][0] != '1' || game->grid[i][game->width - 1] != '1')
			error_msg("The map is not properly bounded with walls");
		i++;
	}
}
