/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:29:35 by jotrujil          #+#    #+#             */
/*   Updated: 2023/12/11 20:42:57 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*auxs1;
	unsigned char	*auxs2;

	auxs1 = (unsigned char *)s1;
	auxs2 = (unsigned char *)s2;
	while (n--)
	{
		if (*auxs1 != *auxs2)
			return (*auxs1 - *auxs2);
		auxs1++;
		auxs2++;
	}
	return (0);
}
/* #include <stdio.h>
#include <string.h>
int main(void)
{
	printf("%d\n", ft_memcmp("holaa", "hola", 5));
	printf("%d\n", memcmp("holaa", "hola", 5));
}
 */