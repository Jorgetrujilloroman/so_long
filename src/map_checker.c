/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:54:45 by jotrujil          #+#    #+#             */
/*   Updated: 2024/10/01 19:24:38 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_format(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4) != 0)
		error_msg("Invalid file format. Please, provide a valid .ber map file");
}

void	map_empty_check(char *map)
{
	if (!map[0])
		error_msg("Empty map, please provide a valid map.");
}

void	map_empty_lines_check(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && map[i + 1] == '\n'))
			error_msg("Map contain empty lines. Please provide a valid map.");
		i++;
	}
}

void	map_content_check(char *map)
{
	size_t	i;
	size_t	player;
	size_t	exit;
	size_t	fish;

	i = 0;
	player = 0;
	exit = 0;
	fish = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			player++;
		if (map[i] == 'E')
			exit++;
		if (map[i] == 'C')
			fish++;
		if (!ft_strchr("10PECX\n", map[i]))
			error_msg("Invalid characters on map. Please provide a valid map.");
		i++;
	}
	if (player != 1 || exit != 1 || fish < 1)
		error_msg("Invalid map content. Please provide a valid map.");
}

void	map_shape_check(char **grid)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(grid[0]);
	while (grid[i])
	{
		if (ft_strlen(grid[i]) != len)
			error_msg("Invalid map shape. Please provide a rectangular map.");
		i++;
	}
}
