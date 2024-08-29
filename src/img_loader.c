/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:41:38 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/29 11:32:14 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*load_all_textures(mlx_t *mlx, t_img *img)
{
	load_texture(mlx, "./sprites/sand.png", &img->sand);
	load_texture(mlx, "./sprites/coral.png", &img->coral);
	load_texture(mlx, "./sprites/fish.png", &img->fish);
	load_texture(mlx, "./sprites/exit_open.png", &img->exit_open);
	load_texture(mlx, "./sprites/exit_closed.png", &img->exit_closed);
	load_texture(mlx, "./sprites/dolphin.png", &img->dolphin);
	load_texture(mlx, "./sprites/enemy.png", &img->enemy);
	return (img);
}

void	load_texture(mlx_t *mlx, char *file_path, mlx_image_t **texture)
{
	mlx_texture_t	*tmp_texture;

	tmp_texture = mlx_load_png(file_path);
	if (!tmp_texture)
		error_msg("Problem loading PNG");
	*texture = mlx_texture_to_image(mlx, tmp_texture);
	if (!*texture)
		error_msg("Problem with texture");
	mlx_delete_texture(tmp_texture);
}

void	load_dolphin_textures(t_game *game)
{
	game->dolphin_up = mlx_load_png("./sprites/dolphin_up.png");
	if (!game->dolphin_up)
		error_msg("Problem loading PNG file");
	game->dolphin_down = mlx_load_png("./sprites/dolphin_down.png");
	if (!game->dolphin_down)
		error_msg("Problem loading PNG file");
	game->dolphin_left = mlx_load_png("./sprites/dolphin_left.png");
	if (!game->dolphin_left)
		error_msg("Problem loading PNG file");
	game->dolphin_right = mlx_load_png("./sprites/dolphin_right.png");
	if (!game->dolphin_right)
		error_msg("Problem loading PNG file");
}
