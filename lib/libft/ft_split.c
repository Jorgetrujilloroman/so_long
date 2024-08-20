/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:03:01 by jotrujil          #+#    #+#             */
/*   Updated: 2024/01/11 19:32:09 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	*get_word(char const *s, char c, size_t *i)
{
	size_t	start;

	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	return (ft_substr(s, start, *i - start));
}

void	free_strarray(char **strarray, size_t pos)
{
	while (pos > 0)
		free(strarray[--pos]);
	free(strarray);
}

char	**ft_split(char const *s, char c)
{
	char	**strarray;
	size_t	i;
	size_t	pos;

	strarray = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!strarray)
		return (NULL);
	i = 0;
	pos = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			strarray[pos] = get_word(s, c, &i);
			if (!strarray[pos++])
			{
				free_strarray(strarray, pos);
				return (NULL);
			}
		}
	}
	strarray[pos] = NULL;
	return (strarray);
}

/* #include <stdio.h>
int main(void){
	char *s1 = "hola que tal";
	char **s2;

	s2 = ft_split(s1, ' ');
	printf("%ld\n", ft_count_words("Hola que tal", ' '));
	printf("%s\n", s2[1]);
} */