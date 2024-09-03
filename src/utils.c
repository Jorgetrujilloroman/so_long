/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:53:01 by jotrujil          #+#    #+#             */
/*   Updated: 2024/09/03 13:08:46 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_msg(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

static void	close_window_after_delay(t_game *game)
{
	static __time_t	start_time = 0;

	if (start_time == 0)
		start_time = time(NULL);
	if (time(NULL) - start_time >= 7)
		mlx_close_window(game->mlx);
}

void	check_game_status(t_game *game)
{
	print_moves_nbr(game);

	if (game->eaten == game->fish)
	{
		if (mlx_image_to_window(game->mlx, game->img->exit_open,
				game->exit_x * PIXELS, game->exit_y * PIXELS) < 0)
			error_msg("Error displaying open exit image to window");
		mlx_delete_image(game->mlx, game->img->exit_closed);
		game->grid[game->exit_y][game->exit_x] = 0;
	}
	if (game->dolphin_y == game->exit_y && game->dolphin_x == game->exit_x)
	{
		game->game_over = 1;
		win_display(game);
		ft_printf("🎉🎇 Congratulations!! 🎇🎉\n");
		ft_printf("🐟🌎 You ate all the fish on earth!! 🌎🐟\n");
		ft_printf("🐬🌌 So long, and Thanks for All the Fish!! 🌌🐬\n");
		mlx_loop_hook(game->mlx, (void (*)(void *))close_window_after_delay,
			game);
	}
}
