/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:13:30 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/04 13:35:57 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max_node(t_node **head)
{
	t_node	*max_node;
	t_node	*curr_node;

	curr_node = *head;
	max_node = *head;
	while (curr_node != NULL)
	{
		if (curr_node->val > max_node->val)
			max_node = curr_node;
		curr_node = curr_node->next;
	}
	return (max_node);
}

t_node	*find_min_node(t_node **head)
{
	t_node	*min_node;
	t_node	*curr_node;

	curr_node = *head;
	min_node = *head;
	while (curr_node != NULL)
	{
		if (curr_node->val < min_node->val)
			min_node = curr_node;
		curr_node = curr_node->next;
	}
	return (min_node);
}

//This func will rotate both stack
//unless either target node of cheapest is on top in A
//or cheapest itself is on top of B
void	rotate_both_till(t_node **stack_a, t_node **stack_b,
										t_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target
			&& *stack_b != cheapest_node)
		rotate_both(stack_a, stack_b);
	update_pos(stack_a);
	update_pos(stack_b);
}

//This func will reverse rotate both stack
//unless either target node of cheapest is on top in A
//or cheapest itself is on top of B
void	rev_rotate_both_till(t_node **stack_a, t_node **stack_b,
										t_node *cheapest_node)
{
	while (*stack_a != cheapest_node->target
			&& *stack_b != cheapest_node)
		reverse_rotate_both(stack_a, stack_b);
	update_pos(stack_a);
	update_pos(stack_b);
}
