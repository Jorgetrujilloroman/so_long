/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:25:26 by jotrujil          #+#    #+#             */
/*   Updated: 2023/12/11 19:34:53 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last_pos;

	last_pos = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			last_pos = i;
		i++;
	}
	if (last_pos != -1)
		return ((char *)&s[last_pos]);
	if (s[i] == (char)c)
	{
		last_pos = i;
		return ((char *)&s[last_pos]);
	}
	return (0);
}
/* #include <stdio.h>
#include <string.h>
int main(void){
	printf("%s\n", ft_strrchr("abbbbbbbb", 'a'));
	printf("%s", strrchr("abbbbbbbb", 'a'));
} */
