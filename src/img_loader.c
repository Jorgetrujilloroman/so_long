/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:41:38 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/26 17:23:29 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*load_all_textures(mlx_t *mlx, t_img *img)
{
	load_texture(mlx, img, "./sprites/sand.png", &img->sand);
	load_texture(mlx, img, "./sprites/rock.png", &img->rock);
	load_texture(mlx, img, "./sprites/fish.png", &img->fish);
	load_texture(mlx, img, "./sprites/exit_open.png", &img->exit_open);
	load_texture(mlx, img, "./sprites/exit_close.png", &img->exit_closed);
	load_texture(mlx, img, "./sprites/dolphin.png", &img->dolphin);
	return (img);
}

void	load_texture(mlx_t *mlx, t_img *img, char *file_path,
			mlx_image_t **texture)
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
