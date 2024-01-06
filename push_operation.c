/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:06:31 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/06 13:59:13 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_prev_refs(t_node **stack)
{
	t_node *node;
	
	if (*stack == NULL)
		return ;
	if (get_stack_size(stack) == 1)
	{
		(*stack)->prev = NULL;
		return ; 
	}
	node = *stack;
	node->prev = NULL;
	while (node != NULL)
	{
		if (node->next)
			node->next->prev = node;
		node = node->next;
	}
}

void	push_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_push;
	if (*stack_b == NULL)
		return ;
	node_to_push = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *stack_a;
		node_to_push->next->prev = node_to_push;
		*stack_a = node_to_push;
	}
	update_prev_refs(stack_a);
	update_prev_refs(stack_b);
	ft_putstr_fd("pa\n", 1);
	// printf("STACK_A\n");
	// print_stack(stack_a);
	// printf("STACK_A backward\n");
	// print_stack_backward(stack_a);
	// printf("STACK_B\n");
	// print_stack(stack_b);
	// printf("STACK_B backward\n");
	// print_stack_backward(stack_b);
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_push;
	if (*stack_a == NULL)
		return ;
	
	node_to_push = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	if (*stack_b == NULL)
	{
		*stack_b = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *stack_b;
		node_to_push->next->prev = node_to_push;
		*stack_b = node_to_push;
	}
	
	update_prev_refs(stack_a);
	update_prev_refs(stack_b);
	ft_putstr_fd("pb\n", 1);
	// printf("STACK_A\n");
	// print_stack(stack_a);
	// printf("STACK_A backward\n");
	// print_stack_backward(stack_a);
	// ft_putstr_fd("pb\n", 1);
	// printf("STACK_B\n");
	// print_stack(stack_b);
	// printf("STACK_B backward\n");
	// print_stack_backward(stack_b);
}
