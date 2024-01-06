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

void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	//free(argv - 1);
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

//ADD case ./push_swap "1 -3 4 5 9"
int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	
	if (argc < 2)
		exit_with_err(NULL);
	if (argc == 2)
	{
		if (is_space_inside(argv[1]))
			stack_a = init_stack_qts(argv[1]);
		else
			return (EXIT_SUCCESS);
	}
	else
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
