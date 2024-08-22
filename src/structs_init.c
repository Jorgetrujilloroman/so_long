/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:09:45 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/22 18:13:55 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	data_init(char *map)
{
	char	*map_str;
	char	**map_array;
	t_game	*data;

	map_str = read_map(map);
}
