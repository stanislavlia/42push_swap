/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operationc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:18:57 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/06 15:48:00 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **stack_a, int verbose)
{
	t_node	*head;
	t_node	*temp_node;

	head = *stack_a;
	if (head->next == NULL)
		return ;
	temp_node = head->next;
	head->next = temp_node->next;
	temp_node->prev = head;
	temp_node->next = head;
	head->prev = temp_node;
	*stack_a = temp_node;
	head->curr_pos = 1;
	temp_node->curr_pos = 0;
	if (verbose)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_node **stack_b, int verbose)
{
	t_node	*head;
	t_node	*temp_node;

	head = *stack_b;
	if (head->next == NULL)
		return ;
	temp_node = head->next;
	head->next = temp_node->next;
	temp_node->prev = head;
	temp_node->next = head;
	head->prev = temp_node;
	*stack_b = temp_node;
	head->curr_pos = 1;
	temp_node->curr_pos = 0;
	if (verbose)
		ft_putstr_fd("sb\n", 1);
}

void	swap_both(t_node **stack_a, t_node **stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	ft_putstr_fd("ss\n", 1);
}
