/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:32:03 by jotrujil          #+#    #+#             */
/*   Updated: 2023/12/19 18:59:05 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	tlen;
	size_t	i;
	char	*r;

	s1len = ft_strlen(s1);
	tlen = s1len + ft_strlen(s2);
	r = malloc(tlen + 1);
	if (!r)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		r[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		r[s1len + i] = s2[i];
		i++;
	}
	r[tlen] = '\0';
	return (r);
}

/* #include <stdio.h>
int main(void)
{
	char *s1;
	char *s2;

	s1 = "pitufo ";
	s2 = "mixto, por favor!";

	printf("%s\n", ft_strjoin(s1, s2));
} */
