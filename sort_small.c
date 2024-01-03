/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:59:04 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/03 18:58:24 by sliashko         ###   ########.fr       */
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

//Sort 4 els in A
void	sort_4els(t_node **stack_a, t_node **stack_b)
{
	int	min_val;
	min_val = find_min_node(stack_a)->val;
	if ((*stack_a)->next->val == min_val)
		swap_a(stack_a, TRUE);
	if ((*stack_a)->next->next->val == min_val)
	{
		rotate_a(stack_a, TRUE);
		rotate_a(stack_a, TRUE);
	}
	if ((*stack_a)->next->next->next->val == min_val)
		reverse_rotate_a(stack_a, TRUE);

	//common part
	push_b(stack_a, stack_b);
	sort_3els(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_5els(t_node **stack_a, t_node **stack_b)
{
	int	min_val;
	
	min_val = find_min_node(stack_a)->val;
	if ((*stack_a)->next->val == min_val)
		swap_a(stack_a, TRUE);
	if ((*stack_a)->next->next->val == min_val)
	{
		rotate_a(stack_a, TRUE);
		rotate_a(stack_a, TRUE);
	}
	if ((*stack_a)->next->next->next->val == min_val)
	{
		reverse_rotate_a(stack_a, TRUE);
		reverse_rotate_a(stack_a, TRUE);
	}
	if ((*stack_a)->next->next->next->next->val == min_val)
		reverse_rotate_a(stack_a, TRUE);
	push_b(stack_a, stack_b);
	sort_4els(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_small(t_node **stack_a, t_node **stack_b)
{
	int	n;

	n = get_stack_size(stack_a);
	if (n == 2)
		sort_2els(stack_a);
	if (n == 3)
		sort_3els(stack_a);
	if (n == 4)
		sort_4els(stack_a, stack_b);
	if (n == 5)
		sort_5els(stack_a, stack_b);
}
