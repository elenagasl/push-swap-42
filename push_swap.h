/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:57:43 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/19 17:57:44 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_list1
{
	int				value;
	int				index;
	int				target;
	int				moves_a;
	int				moves_b;
	int				moves_both;
	int				cost;
	struct s_list1	*next;
}	t_list1;

// parsing
t_list1	*parse_1_argument(char *argv);
t_list1	*parse_multiple_arguments(char **argv);
int		is_correct(char *str);
long	ft_atoi_ps(const char *str);
int		check_doubles(t_list1 *stack_a);

// memory
void	free_split(char **split);
void	free_stack(t_list1 **stack);

// stack operations
t_list1	*ft_lstnew_ps(int content);
int		ft_lstsize_ps(t_list1 *lst);
t_list1	*ft_lstlast_ps(t_list1 *lst);
void	ft_lstadd_back_ps(t_list1 **lst, t_list1 *new);

// movements
void	sa(t_list1 **stack_a);
void	sb(t_list1 **stack_b);
void	ss(t_list1 **stack_a, t_list1 **stack_b);
void	pa(t_list1 **stack_b, t_list1 **stack_a);
void	pb(t_list1 **stack_a, t_list1 **stack_b);
void	ra(t_list1 **stack_a);
void	rb(t_list1 **stack_b);
void	rr(t_list1 **stack_a, t_list1 **stack_b);
void	rra(t_list1 **stack_a);
void	rrb(t_list1 **stack_b);
void	rrr(t_list1 **stack_a, t_list1 **stack_b);

// hardcode sorting
void	hardcode_sorting(t_list1 **a, int len_stack_a);
void	sort_two(t_list1 **a);
void	sort_three(t_list1 **a);

// algorithm
void	push_swap(t_list1 **stack_a, t_list1 **stack_b, int len_stack_a);
void	put_target_top(int target_index, t_list1 **stack_a, int len_stack_a);
void	cost_and_execute(t_list1 **stack_a, t_list1 **stack_b, int sa, int sb);
int		ft_abs(int num);
void	initial_steps(t_list1 **stack_a, t_list1 **stack_b,
			int *len_stack_a, int *len_stack_b);
void	index_list(t_list1 **stack_a, t_list1 **stack_b);
int		find_best_lower_in_b(t_list1 *pA, t_list1 *stack_b);
int		find_max_in_b(t_list1 *stack_b);
void	assign_target_a(t_list1 **stack_a, t_list1 **stack_b);
void	set_moves(t_list1 *pA, int size_a, int size_b);
int		calculate_cost(t_list1 *pA, int size_a, int size_b);
int		execute_direct_moves(t_list1 *node, t_list1 **a, t_list1 **b);
void	execute_joint_rotations(t_list1 *node, t_list1 **a, t_list1 **b);
void	execute_remaining_rotations(t_list1 *node, t_list1 **a, t_list1 **b);
void	execute_moves(t_list1 *node, t_list1 **a, t_list1 **b);
int		find_min_greater_than_b(t_list1 *a, int b_value);
int		find_smallest_value(t_list1 *a);
int		assign_target_b(t_list1 **stack_a, t_list1 **stack_b);
int		get_min_index(t_list1 *stack);
void	rotate_to_top(t_list1 **stack_a, int len_stack_a);
#endif
