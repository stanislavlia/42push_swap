/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:13:30 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/03 18:14:41 by sliashko         ###   ########.fr       */
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

