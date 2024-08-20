/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:19:31 by jotrujil          #+#    #+#             */
/*   Updated: 2023/12/18 20:15:28 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*r;
	size_t	dstsize;

	dstsize = ft_strlen(s) + 1;
	r = malloc(dstsize);
	if (!r)
		return (NULL);
	ft_strlcpy(r, s, dstsize);
	return (r);
}
