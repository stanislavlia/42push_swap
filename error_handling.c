/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:35:14 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/06 15:25:24 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_err(t_node **stack)
{
	free_stack(stack);
	ft_putstr_fd("ERROR\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	is_space_inside(char *str)
{
	while (*str)
	{
		if (*str == ' ' || *str == '\n')
			return (TRUE);
		str++;
	}
	return (FALSE);
}

void	check_spaces(char **argv, t_node **head)
{
	while (*argv)
	{
		if (is_space_inside(*argv))
			exit_with_err(head);
		argv++;
	}
}

//runs over stack and look for nbr
int	find_duplicate(t_node **stack, int nbr)
{
	int		count;
	t_node	*curr;

	curr = *stack;
	count = 0;
	while (curr)
	{
		if (curr->val == nbr)
			count++;
		curr = curr->next;
	}
	if (count >= 2)
		return (1);
	return (0);
}

void	check_dups(t_node **stack)
{
	t_node	*curr;

	curr = *stack;
	while (curr)
	{
		if (find_duplicate(stack, curr->val))
			exit_with_err(stack);
		curr = curr->next;
	}
}
