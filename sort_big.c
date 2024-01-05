/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:34:00 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/05 15:49:47 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//update useful info about nodes in stacks
void	update_stacks(t_node **stack_a, t_node **stack_b)
{
	update_pos(stack_a);
	update_pos(stack_b);
	set_targets(stack_a, stack_b);
	set_costs(stack_a, stack_b);
	set_cheapest(stack_b);
}

t_node	*get_cheapest(t_node **stack)
{	
	t_node	*curr;
	t_node *cheapest;
	
	cheapest = NULL;
	curr = *stack;
	while (curr != NULL)
	{
		if (curr->is_cheapest)
			cheapest = curr;
		curr = curr->next;
	}
	return (cheapest);
}

// void	move_cheap_node(t_node **stack_a, t_node **stack_b)
// {
// 	t_node	*cheapest;

// 	cheapest = get_cheapest(stack_b);
// 	if (cheapest->above_mid && cheapest->target->above_mid)
// 		rotate_both_till(stack_a, stack_b, cheapest);
// 	if (!(cheapest->above_mid) && !(cheapest->target->above_mid))
// 		rev_rotate_both_till(stack_a, stack_b, cheapest);
// 	complete_rotation(stack_b, cheapest, 'B');
// 	print_stack(stack_b);
// 	printf("Cheapest in B: %d; its target = %d\n", cheapest->val, cheapest->target->val);
	
// 	complete_rotation(stack_a, cheapest->target, 'A');
// 	push_a(stack_a, stack_b);
// }

void	move_cheap_node(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	cheapest = get_cheapest(stack_b);
	if (cheapest->above_mid && cheapest->target->above_mid)
		rotate_both_till(stack_a, stack_b, cheapest);
	if (!(cheapest->above_mid) && !(cheapest->target->above_mid))
		rev_rotate_both_till(stack_a, stack_b, cheapest);
	complete_rotation(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

//General sorting algorithm
void	general_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*min_node_a;
	int		size_a;
	
	size_a = get_stack_size(stack_a);
	if (size_a <= 5)
	{
		sort_small(stack_a, stack_b);
		return ;
	}
	while (get_stack_size(stack_a) > 3)
		push_b(stack_a, stack_b);
	sort_small(stack_a, stack_b);
	while (get_stack_size(stack_b) > 0)
	while(get_stack_size(stack_b))
	{	
		update_stacks(stack_a, stack_b);
		move_cheap_node(stack_a, stack_b);
	}
	update_pos(stack_a);
	min_node_a = find_min_node(stack_a);
	// while (*stack_a != min_node_a)
	// 	rotate_a(stack_a, TRUE);
	if (min_node_a->above_mid)
		while (*stack_a != min_node_a)
			rotate_a(stack_a, TRUE);
	else
		while (*stack_a != min_node_a)
			reverse_rotate_a(stack_a, TRUE);
}
