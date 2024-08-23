/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:54:45 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/23 13:10:24 by jotrujil         ###   ########.fr       */
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

	i = 0;
}
