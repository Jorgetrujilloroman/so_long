/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:45:50 by jotrujil          #+#    #+#             */
/*   Updated: 2023/12/11 21:47:06 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			count = 0;
			while (haystack[i + j] == needle[j] && i + j < len)
			{
				count++;
				if (count == ft_strlen(needle))
					return ((char *)&haystack[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*largestring;
	const char	*smallstring;

	largestring = "Foo Bar Baz";
	smallstring = "Bar";
	printf("%s\n", ft_strnstr(largestring, smallstring, 12));
	printf("%s", strnstr(largestring, smallstring, 12));
}
 */