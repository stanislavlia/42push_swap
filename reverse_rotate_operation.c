/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:12:48 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/06 15:41:03 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_node **stack_a, int verbose)
{
	t_node	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| get_stack_size(stack_a) == 1)
		return ;
	update_prev_refs(stack_a);
	last = find_last_node(stack_a);
	last->prev->next = NULL;
	last->next = *stack_a;
	last->prev = NULL;
	*stack_a = last;
	last->next->prev = last;
	update_prev_refs(stack_a);
	if (verbose)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_node **stack_b, int verbose)
{
	t_node	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL
		|| get_stack_size(stack_b) == 1)
		return ;
	update_prev_refs(stack_b);
	last = find_last_node(stack_b);
	last->prev->next = NULL;
	last->next = *stack_b;
	last->prev = NULL;
	*stack_b = last;
	last->next->prev = last;
	update_prev_refs(stack_b);
	if (verbose)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_both(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_a(stack_a, 0);
	reverse_rotate_b(stack_b, 0);
	ft_putstr_fd("rrr\n", 1);
}
