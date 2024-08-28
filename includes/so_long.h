/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:48:31 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/28 13:30:46 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"

# include <stdio.h>
# include <fcntl.h>

# define PIXELS 64

typedef struct s_game
{
	char			**grid;
	size_t			width;
	size_t			height;
	size_t			moves;
	size_t			fish;
	size_t			dolphin_x;
	size_t			dolphin_y;
	size_t			exit_x;
	size_t			exit_y;
	mlx_t			*mlx;
	mlx_texture_t	*dolphin_up;
	mlx_texture_t	*dolphin_down;
	mlx_texture_t	*dolphin_left;
	mlx_texture_t	*dolphin_right;
	t_img			*img;
}	t_game;

typedef struct s_img
{
	mlx_image_t	*sand;
	mlx_image_t	*rock;
	mlx_image_t	*fish;
	mlx_image_t	*dolphin;
	mlx_image_t	*enemy;
	mlx_image_t	*exit_closed;
	mlx_image_t	*exit_open;
}	t_img;

void	error_msg(char *msg);

// Map load & checks
void	check_file_format(char *file);
t_game	*data_init(char *map);
char	*read_map(char *map);
void	map_empty_check(char *map);
void	map_empty_lines_check(char *map);
void	map_content_check(char *map);
void	map_shape_check(char **grid);
void	walls_check(t_game	*game);
size_t	count_rows(char **grid);
size_t	count_fish(t_game *game);
size_t	get_element_pos(t_game	*game, char element, char coordinate);

// Images & textures load
t_img	*img_init(mlx_t *mlx);
t_img	*load_all_textures(mlx_t *mlx, t_img *img);
void	load_texture(mlx_t *mlx, t_img *img, char *file_path,
			mlx_image_t **texture);
void	load_dolphin_textures(t_game *game);

// Game
t_game	*game_init(char **grid);

#endif