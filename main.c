/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:53:46 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/03 18:00:14 by sliashko         ###   ########.fr       */
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
		printf(" [ %d ]; pos = %d; above mid? %d \n", stack->val, stack->curr_pos, stack->above_mid);
		stack = stack->next;
	}
}

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

	printf("STACK A\n");
	print_stack(&stack_a);
	printf("STACK B\n");
	print_stack(&stack_b);

	sort_small(&stack_a, &stack_b);

	printf("STACK A\n");
	print_stack(&stack_a);
	printf("STACK B\n");
	print_stack(&stack_b);
	
	printf("MAx = %d; min = %d\n", find_max_val(&stack_a), find_min_val(&stack_a));
	
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (EXIT_FAILURE);
}
