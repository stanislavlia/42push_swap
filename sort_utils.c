/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:13:30 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/03 17:17:12 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_val(t_node **head)
{
	int		max_val;
	t_node	*curr_node;

	curr_node = *head;
	max_val = INT_MIN;
	while (curr_node != NULL)
	{
		if (curr_node->val > max_val)
			max_val = curr_node->val;
		curr_node = curr_node->next;
	}
	return (max_val);
}

int	find_min_val(t_node **head)
{
	int		min_val;
	t_node	*curr_node;

	curr_node = *head;
	min_val = INT_MAX;
	while (curr_node != NULL)
	{
		if (curr_node->val < min_val)
			min_val = curr_node->val;
		curr_node = curr_node->next;
	}
	return (min_val);
}

