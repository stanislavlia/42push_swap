/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:36:56 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/06 16:06:38 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **head)
{
	t_node	*current_node;
	t_node	*next_node;

	if (head == NULL || *head == NULL)
		return ;
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

	i = 0;
	if (argv == NULL)
		return ;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

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
