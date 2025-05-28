/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:11:56 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/16 13:11:57 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list1 **stack_a, t_list1 **stack_b)
{
	t_list1	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	ft_printf("pb\n");
}

void	pa(t_list1 **stack_b, t_list1 **stack_a)
{
	t_list1	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	ft_printf("pa\n");
}

void	sa(t_list1 **stack_a)
{
	t_list1	*first;
	t_list1	*second;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	ft_printf("sa\n");
}

void	sb(t_list1 **stack_b)
{
	t_list1	*first;
	t_list1	*second;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	ft_printf("sb\n");
}

void	ra(t_list1 **stack_a)
{
	t_list1	*first;
	t_list1	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = first;
	ft_printf("ra\n");
}
