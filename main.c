/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:22:40 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/19 16:22:41 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_and_add_node(char *str, t_list1 **stack)
{
	long		num;
	t_list1		*node;

	if (!is_correct(str))
		return (0);
	num = ft_atoi_ps(str);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	node = ft_lstnew_ps((int)num);
	if (!node)
		return (0);
	ft_lstadd_back_ps(stack, node);
	return (1);
}

t_list1	*parse_1_argument(char *argv)
{
	char	**nums;
	int		i;
	t_list1	*stack_a;

	stack_a = NULL;
	if (!argv || !argv[0])
		return (NULL);
	nums = ft_split(argv, ' ');
	if (!nums[0])
		return (free_split(nums), NULL);
	i = 0;
	while (nums[i])
	{
		if (!validate_and_add_node(nums[i], &stack_a))
		{
			free_split(nums);
			if (stack_a)
				free_stack(&stack_a);
			return (NULL);
		}
		i++;
	}
	free_split(nums);
	return (stack_a);
}

t_list1	*parse_multiple_arguments(char **argv)
{
	int			i;
	t_list1		*stack_a;

	i = 0;
	stack_a = NULL;
	while (argv[i])
	{
		if (!validate_and_add_node(argv[i], &stack_a))
		{
			if (stack_a)
				free_stack(&stack_a);
			return (NULL);
		}
		i++;
	}
	return (stack_a);
}

int	check_sorted(t_list1 *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list1	*stack_a;
	t_list1	*stack_b;
	int		len_stack_a;

	stack_b = NULL;
	if (argc <= 1)
		return (0);
	if (argc == 2 && (!argv[1][0] || argv[1][0] == ' '))
		return (write(2, "Error\n", 6), 1);
	if (argc == 2)
		stack_a = parse_1_argument(argv[1]);
	else
		stack_a = parse_multiple_arguments(argv + 1);
	if (!stack_a)
		return (write(2, "Error\n", 6), 1);
	if (check_doubles(stack_a))
		return (free_stack(&stack_a), write(2, "Error\n", 6), 1);
	if (check_sorted(stack_a))
		return (0);
	len_stack_a = ft_lstsize_ps(stack_a);
	if (len_stack_a <= 3)
		hardcode_sorting(&stack_a, len_stack_a);
	else
		push_swap(&stack_a, &stack_b, len_stack_a);
	return (free_stack(&stack_a), 0);
}
