/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:14:49 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/22 18:58:20 by jotrujil         ###   ########.fr       */
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
		close(fd);
		return (map_readed);
	}
}
