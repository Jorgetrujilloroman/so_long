/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:14:03 by jotrujil          #+#    #+#             */
/*   Updated: 2023/12/19 16:26:00 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;
	size_t	j;
	size_t	strlen;

	j = 0;
	i = start;
	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
	if (len > strlen - start)
		len = strlen - start;
	r = malloc(len + 1);
	if (!r)
		return (NULL);
	while (s[i] != '\0' && len > 0)
	{
		r[j++] = s[i++];
		len--;
	}
	r[j] = '\0';
	return (r);
}
/* 
#include <stdio.h>
int main(void)
{
	char *str = "";

	printf("New string: %s\n", ft_substr(str, 1, 1));
} */
