/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_update_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:40:54 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/04 15:01:44 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_pos(t_node **stack)
{
	t_node	*curr;
	int		i;
	int		mid_idx;

	i = 0;
	if (*stack == NULL)
		return ;
	mid_idx = get_stack_size(stack) / 2;
	curr = (*stack);
	while (curr != NULL)
	{
		curr->curr_pos = i;
		if (i < mid_idx)
			curr->above_mid = TRUE;
		else
			curr->above_mid = FALSE;
		i++;
		curr = curr->next;
	}
}

//Find a target node for element
//stack - is stack where to look for targets
//node - is node that needs a target
// target node - smallest bigger node
void	find_target_node(t_node **stack, t_node *node)
{
	t_node	*curr;
	t_node	*target_candidate;

	curr = *stack;
	if (node->val > find_max_node(stack)->val)
	{
		node->target = find_min_node(stack);
		return ;
	}
	target_candidate = find_max_node(stack);
	while (curr != NULL)
	{
		if (curr->val > node->val && curr->val < target_candidate->val)
			target_candidate = curr;
		curr = curr->next;
	}
	node->target = target_candidate;
}

//Setting targets for nodes in B
void	set_targets(t_node **stack_a, t_node **stack_b)
{
	t_node	*curr;
	
	curr = *stack_b;
	while (curr != NULL)
	{
		find_target_node(stack_a, curr);
		curr = curr->next;
	}
}

//Setting cost for each element in B to move to A 
void	set_costs(t_node **stack_a, t_node **stack_b)
{
	int	size_a;
	int	size_b;
	t_node	*curr;
	
	curr = *stack_b;
	size_a = get_stack_size(stack_a);
	size_b = get_stack_size(stack_b);
	update_pos(stack_a);
	update_pos(stack_b);
	while (curr != NULL)
	{
		curr->cost = curr->curr_pos;
		if (!(curr->above_mid))
			curr->cost = size_b - curr->curr_pos;
		if (curr->target->above_mid)
			curr->cost += curr->target->curr_pos;
		else
			curr->cost += size_a - curr->target->curr_pos;
		curr = curr->next;
	}
}

void	set_cheapest(t_node **stack)
{
	t_node	*curr;
	t_node	*cheapest;

	if (*stack == NULL)
		return ;
	curr = *stack;
	cheapest = *stack;
	while (curr != NULL)
	{
		if (curr->cost < cheapest->cost)
			cheapest = curr;
		curr->is_cheapest = FALSE;
		curr = curr->next;
	}
	cheapest->is_cheapest = TRUE;
}
