/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:52:39 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/21 10:52:41 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_ps(t_list1 *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_list1	*ft_lstnew_ps(int content)
{
	t_list1	*new_node;

	new_node = malloc(sizeof(t_list1));
	if (!new_node)
		return (NULL);
	new_node->value = content;
	new_node->next = NULL;
	return (new_node);
}

t_list1	*ft_lstlast_ps(t_list1 *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_ps(t_list1 **lst, t_list1 *new)
{
	t_list1	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast_ps(*lst);
	last->next = new;
}
