/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:02:25 by jotrujil          #+#    #+#             */
/*   Updated: 2024/01/23 19:01:28 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;

	cdst = (char *)dst;
	csrc = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst <= src)
	{
		while (len--)
		{
			*cdst++ = *csrc++;
		}
	}
	else if (dst > src)
	{
		cdst += len - 1;
		csrc += len - 1;
		while (len--)
		{
			*cdst-- = *csrc--;
		}
	}
	return (dst);
}

//Ref: https://marmota.medium.com/c-language-making-memmove-def8792bb8d5