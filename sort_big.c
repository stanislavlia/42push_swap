/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:34:00 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/04 11:58:16 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		node->target = curr;
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
