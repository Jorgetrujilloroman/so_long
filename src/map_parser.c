/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:14:49 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/28 17:17:11 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *map)
{
	char	*line;
	char	*map_readed;
	int		fd;

	fd = open(map, O_RDONLY);
	map_readed = ft_calloc(1, 1);
	if (!map_readed)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			map_readed = ft_strjoin(map_readed, line);
			free(line);
		}
		else
			break ;
	}
	close(fd);
	return (map_readed);
}

size_t	count_rows(char **grid)
{
	size_t	rows;

	rows = 0;
	while (grid[rows])
		rows++;
	return (rows);
}

size_t	count_fish(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	fish;

	y = 0;
	fish = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == 'C')
				fish++;
			x++;
		}
		y++;
	}
	return (fish);
}

size_t	get_element_pos(t_game	*game, char element, char coordinate)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == element)
			{
				if (coordinate == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
