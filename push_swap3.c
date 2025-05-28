/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:14:36 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/21 12:14:41 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_greater_than_b(t_list1 *a, int b_value)
{
	long	best_diff;
	int		target_index;
	long	diff;

	best_diff = 9223372036854775807L;
	target_index = -1;
	while (a)
	{
		diff = (long)a->value - (long)b_value;
		if (diff > 0 && (diff <= best_diff))
		{
			best_diff = diff;
			target_index = a->index;
		}
		a = a->next;
	}
	return (target_index);
}

int	find_smallest_value(t_list1 *a)
{
	int	min_value;
	int	target_index;

	min_value = 2147483647;
	target_index = -1;
	while (a)
	{
		if (a->value < min_value)
		{
			min_value = a->value;
			target_index = a->index;
		}
		a = a->next;
	}
	return (target_index);
}

int	assign_target_b(t_list1 **stack_a, t_list1 **stack_B)
{
	t_list1	*b;
	int		target_index;

	b = *stack_B;
	target_index = find_min_greater_than_b(*stack_a, b->value);
	if (target_index == -1)
		target_index = find_smallest_value(*stack_a);
	return (target_index);
}

int	get_min_index(t_list1 *stack)
{
	t_list1	*ptr;
	int		min_value;
	int		min_index;
	int		i;

	ptr = stack;
	min_value = 2147483647;
	min_index = 0;
	i = 0;
	while (ptr)
	{
		if (ptr->value < min_value)
		{
			min_value = ptr->value;
			min_index = i;
		}
		ptr = ptr->next;
		i++;
	}
	return (min_index);
}

void	rotate_to_top(t_list1 **stack_a, int len_stack_a)
{
	int	min_index;
	int	i;

	min_index = get_min_index(*stack_a);
	if (min_index <= len_stack_a / 2)
	{
		i = 0;
		while (i < min_index)
		{
			ra(stack_a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < len_stack_a - min_index)
		{
			rra(stack_a);
			i++;
		}
	}
}
