/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:15:27 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/16 13:15:28 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list1 **a)
{
	if (!*a || !(*a)->next)
		return ;
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_list1 **a)
{
	int	x;
	int	y;
	int	z;

	if (!*a || !(*a)->next || !(*a)->next->next)
		return ;
	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	hardcode_sorting(t_list1 **stack_a, int len_stack_a)
{
	if (len_stack_a == 1)
		return (free_stack(stack_a));
	if (len_stack_a == 2)
		return (sort_two(stack_a));
	if (len_stack_a == 3)
		return (sort_three(stack_a));
}
