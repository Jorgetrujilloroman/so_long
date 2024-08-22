/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:31:06 by jotrujil          #+#    #+#             */
/*   Updated: 2024/08/22 12:58:17 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_msg("Please, use one .ber map file as argument ¬¬'");
	check_file_format(argv[1]);
}
