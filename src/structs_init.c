/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:09:45 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/26 17:29:35 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*data_init(char *map)
{
	char	*map_str;
	char	**map_array;
	t_game	*data;

	map_str = read_map(map);
	map_empty_check(map_str);
	map_empty_lines_check(map_str);
	map_content_check(map_str);
	map_array = ft_split(map_str, '\n');
	map_shape_check(map_array);
}

t_img	*img_init(mlx_t *mlx)
{
	t_img	*assets;

	assets = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!assets)
		return (NULL);
	assets = load_all_textures(mlx, assets);
	return (assets);
}
