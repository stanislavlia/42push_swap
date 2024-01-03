/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:59:04 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/03 17:04:48 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Functions in this file are made only for stack A
*/


void	sort_2els(t_node **head)
{
	if ((*head)->val > (*head)->next->val)
		swap_a(head, TRUE);
}

void	sort_3els(t_node **head)
{
	int	vals[3];
	
	vals[0] = (*head)->val;
	vals[1] = (*head)->next->val;
	vals[2] = (*head)->next->next->val;
	if ((vals[0] < vals[1]) && (vals[1] < vals[2]) && (vals[0] < vals[2]))
		return ;
	if ((vals[0] > vals[1]) && (vals[1] < vals[2]) && (vals[0] > vals[2]))
		rotate_a(head, TRUE);
	if ((vals[0] < vals[1]) && (vals[1] > vals[2]) && (vals[0] < vals[2]))
	{
		reverse_rotate_a(head, TRUE);
		swap_a(head, TRUE);
	}
	if ((vals[0] > vals[1]) && (vals[1] > vals[2]) && (vals[0] > vals[2]))
	{
		rotate_a(head, TRUE);
		swap_a(head, TRUE);
	}
	if ((vals[0] > vals[1]) && (vals[1] < vals[2]) && (vals[0] < vals[2]))
		swap_a(head, TRUE);
	if ((vals[0] < vals[1]) && (vals[1] > vals[2]) && (vals[0] > vals[2]))
		reverse_rotate_a(head, TRUE);
}
