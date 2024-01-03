/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:06:31 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/03 15:15:04 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **stack_a, t_node **stack_b)
{
	t_node *temp_node;
	
	if (stack_b == NULL || *stack_b == NULL)
		return ;
	ft_putstr_fd("pa\n", 1);
	temp_node = *stack_b;
	*stack_b = (*stack_b)->next;
	if (temp_node ->next != NULL)
		temp_node->next->prev = NULL; 
	temp_node->next = *stack_a;
	if (*stack_a != NULL)
		temp_node->next->prev = temp_node;
	*stack_a = temp_node;
	(*stack_a)->prev = NULL;
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	t_node *temp_node;
	
	if (stack_a == NULL || *stack_a == NULL)
		return ;
	ft_putstr_fd("pb\n", 1);
	temp_node = *stack_a;
	*stack_a = (*stack_a)->next;
	if (temp_node ->next != NULL)
		temp_node->next->prev = NULL;
	temp_node->next = *stack_b;
	if (*stack_b != NULL)
		temp_node->next->prev = temp_node;
	*stack_b = temp_node;
	(*stack_b)->prev = NULL;	
}
