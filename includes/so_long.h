/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:48:31 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/23 13:05:42 by jotrujil         ###   ########.fr       */
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
	char	**grid;
	size_t	width;
	size_t	height;
	mlx_t	mlx;

}	t_game;

void	error_msg(char *msg);
void	check_file_format(char *file);
t_game	*data_init(char *map);
char	*read_map(char *map);
void	map_empty_check(char *map);
void	map_empty_lines_check(char *map);

#endif