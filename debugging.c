#include "push_swap.h"

//TODO
// 1) Try to comment my small algorithm and try to catch problem using big algorithm
// 2) Try Xcode to debug and catch problem

// ./push_swap 5 7 6 1 4 10 3 2 9 8 - SOLVED
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

	//print_stack(&stack_a);
	
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (EXIT_SUCCESS);
}
