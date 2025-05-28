/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:33:52 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/21 10:33:55 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list1 **stack_b)
{
	t_list1	*first;
	t_list1	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = first;
	ft_printf("rb\n");
}

void	rra(t_list1 **stack_a)
{
	t_list1	*prev;
	t_list1	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	prev = NULL;
	last = *stack_a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_printf("rra\n");
}

void	rrb(t_list1 **stack_b)
{
	t_list1	*prev;
	t_list1	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	prev = NULL;
	last = *stack_b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	ft_printf("rrb\n");
}

void	ss(t_list1 **stack_a, t_list1 **stack_b)
{
	t_list1	*first_a;
	t_list1	*second_a;
	t_list1	*first_b;
	t_list1	*second_b;

	if (*stack_a && (*stack_a)->next)
	{
		first_a = *stack_a;
		second_a = first_a->next;
		first_a->next = second_a->next;
		second_a->next = first_a;
		*stack_a = second_a;
	}
	if (*stack_b && (*stack_b)->next)
	{
		first_b = *stack_b;
		second_b = first_b->next;
		first_b->next = second_b->next;
		second_b->next = first_b;
		*stack_b = second_b;
	}
	ft_printf("ss\n");
}

void	rr(t_list1 **stack_a, t_list1 **stack_b)
{
	t_list1	*first;
	t_list1	*last;

	if (*stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		*stack_a = first->next;
		first->next = NULL;
		last = *stack_a;
		while (last->next)
			last = last->next;
		last->next = first;
	}
	if (*stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		*stack_b = first->next;
		first->next = NULL;
		last = *stack_b;
		while (last->next)
			last = last->next;
		last->next = first;
	}
	ft_printf("rr\n");
}
