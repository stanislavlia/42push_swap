/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:34:00 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/04 13:05:09 by sliashko         ###   ########.fr       */
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
