/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:12:22 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/21 12:12:23 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_moves(t_list1 *pA, int size_a, int size_b)
{
	if (pA->index <= size_a / 2)
		pA->moves_a = pA->index;
	else
		pA->moves_a = -(size_a - pA->index);
	if (pA->target <= size_b / 2)
		pA->moves_b = pA->target;
	else
		pA->moves_b = -(size_b - pA->target);
	pA->moves_both = 0;
}

int	calculate_cost(t_list1 *pA, int size_a, int size_b)
{
	int	total_moves;
	int	abs_a;
	int	abs_b;

	set_moves(pA, size_a, size_b);
	abs_a = ft_abs(pA->moves_a);
	abs_b = ft_abs(pA->moves_b);
	if ((pA->moves_a >= 0 && pA->moves_b >= 0)
		|| (pA->moves_a < 0 && pA->moves_b < 0))
	{
		if (abs_a > abs_b)
			pA->moves_both = pA->moves_b;
		else
			pA->moves_both = pA->moves_a;
		total_moves = ft_abs(pA->moves_both);
		total_moves += ft_abs(pA->moves_a - pA->moves_both);
		total_moves += ft_abs(pA->moves_b - pA->moves_both);
	}
	else
		total_moves = abs_a + abs_b;
	return (total_moves + 1);
}

int	execute_direct_moves(t_list1 *node, t_list1 **a, t_list1 **b)
{
	if (node->moves_a == 1 && node->moves_b == 1)
	{
		rr(a, b);
		pb(a, b);
		return (1);
	}
	if (node->moves_a == 1 && node->moves_b == 0)
	{
		ra(a);
		pb(a, b);
		return (1);
	}
	if (node->moves_a == 0 && node->moves_b == 1)
	{
		rb(b);
		pb(a, b);
		return (1);
	}
	return (0);
}

void	execute_joint_rotations(t_list1 *node, t_list1 **a, t_list1 **b)
{
	int	i;

	if (node->moves_both > 0)
	{
		i = node->moves_both;
		while (i > 0)
		{
			rr(a, b);
			i--;
		}
	}
	else if (node->moves_both < 0)
	{
		i = -node->moves_both;
		while (i > 0)
		{
			rrr(a, b);
			i--;
		}
	}
}

void	execute_remaining_rotations(t_list1 *node, t_list1 **a, t_list1 **b)
{
	int	remaining_a;
	int	remaining_b;

	remaining_a = ft_abs(node->moves_a - node->moves_both);
	remaining_b = ft_abs(node->moves_b - node->moves_both);
	while (remaining_a > 0)
	{
		if (node->moves_a > 0)
			ra(a);
		else
			rra(a);
		remaining_a--;
	}
	while (remaining_b > 0)
	{
		if (node->moves_b > 0)
			rb(b);
		else
			rrb(b);
		remaining_b--;
	}
}
