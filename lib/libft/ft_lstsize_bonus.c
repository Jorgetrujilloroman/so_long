/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:28:09 by jotrujil          #+#    #+#             */
/*   Updated: 2024/01/04 18:57:03 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*next_node;

	size = 0;
	next_node = lst;
	while (next_node != NULL)
	{
		next_node = next_node->next;
		size++;
	}
	return (size);
}
