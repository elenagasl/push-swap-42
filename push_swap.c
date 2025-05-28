/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:52:04 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/15 16:52:07 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

void	cost_and_execute(t_list1 **stack_a, t_list1 **stack_b, int sa, int sb)
{
	t_list1	*pa;
	t_list1	*min_node;
	int		min_cost;
	int		cost;

	pa = *stack_a;
	min_node = NULL;
	min_cost = 2147483647;
	while (pa)
	{
		cost = calculate_cost(pa, sa, sb);
		if (cost == 1)
		{
			min_node = pa;
			break ;
		}
		if (cost < min_cost)
		{
			min_cost = cost;
			min_node = pa;
		}
		pa = pa->next;
	}
	if (min_node)
		execute_moves(min_node, stack_a, stack_b);
}

void	execute_moves(t_list1 *node, t_list1 **a, t_list1 **b)
{
	if (execute_direct_moves(node, a, b))
		return ;
	execute_joint_rotations(node, a, b);
	execute_remaining_rotations(node, a, b);
	pb(a, b);
}

void	put_target_top(int target_index, t_list1 **stack_a, int len_stack_a)
{
	int	i;

	if (target_index <= len_stack_a / 2)
	{
		i = 0;
		while (i < target_index)
		{
			ra(stack_a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < len_stack_a - target_index)
		{
			rra(stack_a);
			i++;
		}
	}
}

void	push_swap(t_list1 **stack_a, t_list1 **stack_b, int len_stack_a)
{
	int	len_stack_b;
	int	target_index;

	len_stack_b = 0;
	initial_steps(stack_a, stack_b, &len_stack_a, &len_stack_b);
	while (len_stack_a > 3)
	{
		index_list(stack_a, stack_b);
		assign_target_a(stack_a, stack_b);
		cost_and_execute(stack_a, stack_b, len_stack_a, len_stack_b);
		len_stack_a--;
		len_stack_b++;
	}
	sort_three(stack_a);
	while (len_stack_b > 0)
	{
		index_list(stack_a, stack_b);
		target_index = assign_target_b(stack_a, stack_b);
		put_target_top(target_index, stack_a, len_stack_a);
		pa(stack_b, stack_a);
		len_stack_b--;
		len_stack_a++;
	}
	rotate_to_top(stack_a, len_stack_a);
}
