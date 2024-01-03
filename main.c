/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:53:46 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/03 15:16:06 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	print_stack(t_node **head)
{	
	t_node *stack;
	
	stack = *head;
	while (stack != NULL)
	{
		printf(" [ %d ]; pos = %d; index = %d; \n", stack->val, stack->curr_pos, stack->index);
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

	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);

	

	printf("STACK A\n");
	print_stack(&stack_a);
	printf("STACK B\n");
	print_stack(&stack_b);


	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	

	printf("STACK A\n");
	print_stack(&stack_a);
	printf("STACK B\n");
	print_stack(&stack_b);
}
