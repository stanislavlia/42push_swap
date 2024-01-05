#include "push_swap.h"

//./push_swap  5 7 6 1 4 10 3 2 9 8   


// int	main(int argc, char **argv)
// {
// 	t_node	*stack_a;
// 	t_node	*stack_b;

// 	if (argc < 2)
// 	{
// 		printf("Too few args\n");
// 		return (EXIT_FAILURE);
// 	}
	
// 	stack_a = init_stack(argv + 1);
// 	stack_b = NULL;
	
// 	printf("----A----\n");
// 	print_stack(&stack_a);

// 	printf("---A_backwards---\n");
// 	print_stack_backward(&stack_a);

// 	push_b(&stack_a, &stack_b);
// 	push_b(&stack_a, &stack_b);
// 	push_b(&stack_a, &stack_b);
// 	push_b(&stack_a, &stack_b);

// 	printf("----A----\n");
// 	print_stack(&stack_a);

// 	printf("---A_backwards---\n");
// 	print_stack_backward(&stack_a);

// 	push_a(&stack_a, &stack_b);
// 	push_a(&stack_a, &stack_b);
// 	push_a(&stack_a, &stack_b);
// 	push_a(&stack_a, &stack_b);

// 	printf("----A----\n");
// 	print_stack(&stack_a);

// 	printf("---A_backwards---\n");
// 	print_stack_backward(&stack_a);

// 	reverse_rotate_a(&stack_a, TRUE);

// 	printf("----A----\n");
// 	print_stack(&stack_a);

// 	printf("---A_backwards---\n");
// 	print_stack_backward(&stack_a);


// 	//general_sort(&stack_a, &stack_b);
// 	free_stack(&stack_a);
// 	free_stack(&stack_b);
// 	return (EXIT_FAILURE);
// }


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
	
	general_sort(&stack_a, &stack_b);

	//print_stack(&stack_a);
	
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (EXIT_FAILURE);
}
