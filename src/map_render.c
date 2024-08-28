/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:46:02 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/28 18:00:25 by jotrujil         ###   ########.fr       */
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
