/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:09:51 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/21 12:09:53 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initial_steps(t_list1 **stack_a, t_list1 **stack_b,
						int *len_stack_a, int *len_stack_b)
{
	if (*len_stack_a == 4)
	{
		pb(stack_a, stack_b);
		*len_stack_a -= 1;
		*len_stack_b += 1;
	}
	else
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		*len_stack_a -= 2;
		*len_stack_b += 2;
	}
}

void	index_list(t_list1 **stack_a, t_list1 **stack_b)
{
	t_list1	*pa;
	t_list1	*pb;
	int		i;

	pa = *stack_a;
	i = 0;
	while (pa)
	{
		pa->index = i;
		pa = pa->next;
		i++;
	}
	pb = *stack_b;
	i = 0;
	while (pb)
	{
		pb->index = i;
		pb = pb->next;
		i++;
	}
}

int	find_best_lower_in_b(t_list1 *pa, t_list1 *stack_b)
{
	t_list1		*pb;
	long		best_diff;
	int			target_index;
	long		diff;

	pb = stack_b;
	best_diff = -9223372036854775807L;
	target_index = -1;
	while (pb)
	{
		diff = (long)pb->value - (long)pa->value;
		if (diff < 0 && diff > best_diff)
		{
			best_diff = diff;
			target_index = pb->index;
		}
		pb = pb->next;
	}
	return (target_index);
}

int	find_max_in_b(t_list1 *stack_b)
{
	t_list1	*pb;
	int		max_value;
	int		target_index;

	pb = stack_b;
	max_value = -2147483648;
	target_index = -1;
	while (pb)
	{
		if (pb->value > max_value)
		{
			max_value = pb->value;
			target_index = pb->index;
		}
		pb = pb->next;
	}
	return (target_index);
}

void	assign_target_a(t_list1 **stack_a, t_list1 **stack_b)
{
	t_list1	*pa;

	pa = *stack_a;
	while (pa)
	{
		pa->target = find_best_lower_in_b(pa, *stack_b);
		if (pa->target == -1)
			pa->target = find_max_in_b(*stack_b);
		pa = pa->next;
	}
}
