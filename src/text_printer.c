/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:37:57 by jotrujil          #+#    #+#             */
/*   Updated: 2024/09/03 13:07:34 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_background(mlx_t *mlx, int x, int y, t_txt_bg bg)
{
	int			i;
	int			j;
	mlx_image_t	*bg_image;

	bg_image = mlx_new_image(mlx, bg.width, bg.height);
	if (!bg_image)
		return ;
	i = 0;
	while (i < bg.height)
	{
		j = 0;
		while (j < bg.width)
		{
			mlx_put_pixel(bg_image, j, i, bg.color);
			j++;
		}
		i++;
	}
	mlx_image_to_window(mlx, bg_image, x, y);
}

void	print_text(t_game *game)
{
	t_txt_bg	bg;

	bg.width = 220;
	bg.height = 50;
	bg.color = 0x3E2D00FF;
	draw_background(game->mlx, 5, game->height * 64 - 57, bg);
	bg.width = 210;
	bg.height = 40;
	bg.color = 0x08006CFF;
	draw_background(game->mlx, 10, game->height * 64 - 52, bg);
	game->img->moves_text = mlx_put_string(game->mlx, "Moves: ",
			16, game->height * 64 - 44);
	mlx_image_to_window(game->mlx, game->img->fish,
		108, game->height * 64 - 64);
	mlx_put_string(game->mlx, ": ", 160, game->height * 64 - 44);
}

void	print_eaten_fish(t_game *game)
{
	char	*str;

	str = ft_itoa(game->eaten);
	if (game->img->fish_counter)
		mlx_delete_image(game->mlx, game->img->fish_counter);
	game->img->fish_counter = mlx_put_string(game->mlx, str,
			180, game->height * 64 - 44);
	free(str);
}

void	print_moves_nbr(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	if (game->img->moves_counter)
		mlx_delete_image(game->mlx, game->img->moves_counter);
	game->img->moves_counter = mlx_put_string(game->mlx, str,
			80, game->height * 64 - 44);
	free(str);
}

void	win_display(t_game *game)
{
	t_txt_bg	bg;
	int			x_center;
	int			y_center;
	char		*str;

	str = "Congratulations!! You won the game!";

	bg.width = 520;
    bg.height = 120;
    bg.color = 0x3E2D00FF;

	x_center = (game->mlx->width - bg.width) / 2;
	y_center = (game->mlx->height - bg.height) / 2;
	draw_background(game->mlx, x_center, y_center, bg);
	bg.width = 500;
	bg.height = 100;
	bg.color = 0x08006CFF;
	draw_background(game->mlx, x_center + 10, y_center + 10, bg);
	mlx_put_string(game->mlx, str, x_center + 80, y_center + 50);
}
