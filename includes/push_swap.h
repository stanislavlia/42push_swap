/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:17:52 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/06 17:17:28 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

typedef struct node
{
	int			curr_pos;
	int			index;
	int			val;
	struct node	*next;
	struct node	*prev;
	struct node	*target;
	int			cost;
	int			is_cheapest;
	int			above_mid;
}			t_node;

typedef struct push_swap
{
	t_node	*stack_a;
	t_node	*stack_b;
}			t_push_swap;

//Utils
// int		ft_atoi(const char *str);
int		ft_atoi_protected(char *str, t_node **head);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);

//Linkedlist utils
t_node	*find_last_node(t_node **head);
t_node	*init_stack(char **args);
t_node	*init_stack_qts(char *args);
int		get_stack_size(t_node **head);
void	update_pos(t_node **stack);
int		is_sorted(t_node **stack);

//Stack operations
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
void	swap_a(t_node **stack_a, int verbose);
void	swap_b(t_node **stack_b, int verbose);
void	swap_both(t_node **stack_a, t_node **stack_b);
void	rotate_a(t_node **stack_a, int verbose);
void	rotate_b(t_node **stack_b, int verbose);
void	rotate_both(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_a(t_node **stack_a, int verbose);
void	reverse_rotate_b(t_node **stack_b, int verbose);
void	reverse_rotate_both(t_node **stack_a, t_node **stack_b);

//Sorting
void	sort_3els(t_node **head);
void	sort_4els(t_node **stack_a, t_node **stack_b);
void	sort_5els(t_node **stack_a, t_node **stack_b);
void	sort_small(t_node **stack_a, t_node **stack_b);
t_node	*find_max_node(t_node **head);
t_node	*find_min_node(t_node **head);
void	find_target_node(t_node **stack, t_node *node);
void	set_targets(t_node **stack_a, t_node **stack_b);
void	set_costs(t_node **stack_a, t_node **stack_b);
void	set_cheapest(t_node **stack);
void	update_stacks(t_node **stack_a, t_node **stack_b);
t_node	*get_cheapest(t_node **stack);
void	rotate_both_till(t_node **stack_a, t_node **stack_b,
			t_node *cheapest_node);
void	rev_rotate_both_till(t_node **stack_a, t_node **stack_b,
			t_node *cheapest_node);
void	complete_rotation(t_node **stack_a, t_node **stack_b);
void	general_sort(t_node **stack_a, t_node **stack_b);

//Error handling and parsing
void	free_stack(t_node **head);
void	update_prev_refs(t_node **stack);
void	exit_with_err(t_node **stack);
int		is_space_inside(char *str);
void	check_spaces(char **argv, t_node **head);
void	check_dups(t_node **stack);
void	free_matrix(char **argv);

#endif
