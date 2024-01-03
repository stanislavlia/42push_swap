/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_update_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:40:54 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/03 16:50:52 by sliashko         ###   ########.fr       */
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
