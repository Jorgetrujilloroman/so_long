/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:53:47 by jotrujil          #+#    #+#             */
/*   Updated: 2023/12/11 18:47:27 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] != '\0' && dst_len + i < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char	string1[20] = "Hola ";
	char	string2[20] = "que tal?";

	char	string3[20] = "Hola ";
	char	string4[20] = "que tal?";

	printf("%zu \n%s", ft_strlcat(string1, string2, 10), string1);
	printf("%zu \n%s", strlcat(string3, string4, 10), string1);
} */