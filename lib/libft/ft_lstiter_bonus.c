/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:51:30 by jotrujil          #+#    #+#             */
/*   Updated: 2024/01/18 16:56:44 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next_node;
	t_list	*current_node;

	current_node = lst;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		f(current_node->content);
		current_node = next_node;
	}
}
