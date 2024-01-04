/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:53:46 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/04 15:05:22 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void free_stack(t_node **head)
{
	t_node *current_node;
	t_node *next_node;

	if (head == NULL || *head == NULL)
		return;
	current_node = *head;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	*head = NULL;
}

void	print_stack(t_node **head)
{	
	t_node *stack;
	
	stack = *head;
	while (stack != NULL)
	{
		printf(" [ %d ]; pos = %d;\n", stack->val, stack->curr_pos);
		stack = stack->next;
	}
}

/* TODO

	1) Implement function to set target node (for els in B)
	2) Implement function to compute cost of each el in B
	3) Implement function to rotate untill we have target on top +
	   function to move from B to A and keep A sorted
*/

//DONT forget to check for sorted or not
int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
	{
		printf("Too few args\n");
		return (EXIT_FAILURE);
	}
	
	stack_a = init_stack(argv + 1);

	general_sort(&stack_a, &stack_b);
	
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (EXIT_FAILURE);
}
