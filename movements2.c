/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:35:40 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/21 10:35:41 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list1 **stack)
{
	t_list1	*prev;
	t_list1	*last;

	if (*stack && (*stack)->next)
	{
		prev = NULL;
		last = *stack;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rrr(t_list1 **stack_a, t_list1 **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
