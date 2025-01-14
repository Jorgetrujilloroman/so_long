/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:48:31 by jotrujil          #+#    #+#             */
/*   Updated: 2024/09/04 12:10:51 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# define PIXELS 64

typedef struct s_txt_bg
{
	int			width;
	int			height;
	uint32_t	color;
}	t_txt_bg;

typedef struct s_img
{
	mlx_image_t	*sand;
	mlx_image_t	*coral;
	mlx_image_t	*fish;
	mlx_image_t	*dolphin;
	mlx_image_t	*enemy;
	mlx_image_t	*exit_closed;
	mlx_image_t	*exit_open;
	mlx_image_t	*moves_text;
	mlx_image_t	*moves_counter;
	mlx_image_t	*fish_counter;
}	t_img;


typedef struct s_game
{
	char			**grid;
	int				game_over;
	size_t			width;
	size_t			height;
	size_t			moves;
	size_t			fish;
	size_t			eaten;
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

typedef struct s_enemy_move
{
	int	*x;
	int	*y;
	int	ran_x;
	int	ran_y;
	int	index_x;
	int	index_y;
}	t_enemy_move;

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

// Map Rendering
void	fill_background(t_game *game);
void	render_map(t_game *game);
void	print_text(t_game *game);
void	print_moves_nbr(t_game *game);
void	print_eaten_fish(t_game *game);

// Path checker
void	flood_fill(t_game *game);

// Images & textures load
t_img	*img_init(mlx_t *mlx);
t_img	*load_all_textures(mlx_t *mlx, t_img *img);
void	load_texture(mlx_t *mlx, char *file_path, mlx_image_t **texture);
void	load_dolphin_textures(t_game *game);
bool	mlx_draw_texture(mlx_image_t *image, mlx_texture_t *texture,
			uint32_t x, uint32_t y);
void	win_lose_display(t_game *game, char result);

// Game
t_game	*game_init(char **grid);
void	check_game_status(t_game *game);
void	close_window_after_delay(t_game *game);
void	free_grid(char **grid, size_t height);
void	free_game(t_game *game);

// Movement & directions
void	move_hook(mlx_key_data_t key_data, void *data);
t_game	*move_up(t_game *game);
t_game	*move_down(t_game *game);
t_game	*move_left(t_game *game);
t_game	*move_right(t_game *game);
void	enemy_patrol(void *temp_game);

#endif