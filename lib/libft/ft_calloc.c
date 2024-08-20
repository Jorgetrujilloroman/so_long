/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:53:32 by jotrujil          #+#    #+#             */
/*   Updated: 2024/01/25 20:49:48 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;

	pointer = malloc(nmemb * size);
	if (pointer == NULL)
		return (NULL);
	ft_memset(pointer, 0, nmemb * size);
	return (pointer);
}
/* #include <stdio.h>
int	main(void)
{
	int *entero = ft_calloc(2, 2);
	if (entero == NULL)
		printf("No hay suficiente memoria para continuar...\n");
} */
