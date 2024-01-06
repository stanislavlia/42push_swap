#include "push_swap.h"

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

void	print_stack_backward(t_node **head)
{	
	t_node *stack;
	
	stack = *head;
	while (stack != NULL)
	{
		stack = stack->next;
	}
	stack = find_last_node(head);
	while (stack != NULL)
	{
		printf(" [ %d ]; pos = %d;\n", stack->val, stack->curr_pos);
		stack = stack->prev;
	}
	
}
//TODO
// 1) Try to comment my small algorithm and try to catch problem using big algorithm
// 2) Try Xcode to debug and catch problem

//DONT FORGET TO TURN ON THE FLAGS!!!
//./push_swap 4 5 1 3 2 - Element 2 just disappears 
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
	stack_b = NULL;
	if (is_sorted(&stack_a))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (EXIT_SUCCESS);
	}
	general_sort(&stack_a, &stack_b);
	
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (EXIT_SUCCESS);
}
