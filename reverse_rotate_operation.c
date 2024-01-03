/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:12:48 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/03 16:18:51 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_node **stack_a, int verbose)
{
	t_node	*temp_node;
	t_node	*last_node;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp_node = find_last_node(stack_a);
	if (temp_node->prev != NULL)
		temp_node->prev->next = NULL;
	temp_node->next = *stack_a;
	(*stack_a)->prev = temp_node;	
	*stack_a = temp_node;
	if (verbose)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_node **stack_b, int verbose)
{
	t_node	*temp_node;
	t_node	*last_node;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp_node = find_last_node(stack_b);
	if (temp_node->prev != NULL)
		temp_node->prev->next = NULL;
	temp_node->next = *stack_b;
	(*stack_b)->prev = temp_node;	
	*stack_b = temp_node;
	if (verbose)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_both(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_a(stack_a, 0);
	reverse_rotate_b(stack_b, 0);
	ft_putstr_fd("rrr\n", 1);	
}


