/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:01:34 by jotrujil          #+#    #+#             */
/*   Updated: 2023/12/20 13:57:09 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	r = malloc(end - start + 1);
	if (!r)
		return (NULL);
	ft_strlcpy(r, &s1[start], end - start + 1);
	return (r);
}

/* #include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "abcHelloWorldcba";
	s2 = "abc";
	printf("%s\n", ft_strtrim(s1, s2));
} */