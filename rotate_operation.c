/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:35:38 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/06 12:15:04 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node **stack_a, int verbose)
{
	t_node *temp_node;
	t_node *last_node;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	update_prev_refs(stack_a);
	temp_node = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	last_node = find_last_node(stack_a);
	last_node->next = temp_node;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	update_prev_refs(stack_a);
	if (verbose)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_node **stack_b, int verbose)
{
	t_node *temp_node;
	t_node *last_node;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	update_prev_refs(stack_b);
	temp_node = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	last_node = find_last_node(stack_b);
	last_node->next = temp_node;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	update_prev_refs(stack_b);
	if (verbose)
		ft_putstr_fd("rb\n", 1);
}

void	rotate_both(t_node **stack_a, t_node **stack_b)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	ft_putstr_fd("rr\n", 1);
}
