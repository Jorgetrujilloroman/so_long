/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:48:31 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/22 13:10:47 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"

# include <stdio.h>

typedef struct s_game
{
	char	**grid;
	size_t	width;
	size_t	height;

}	t_game;

void	error_msg(char *msg);
void	check_file_format(char *file);

#endif