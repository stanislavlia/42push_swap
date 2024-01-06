/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:48:59 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/06 14:34:05 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *find_last_node(t_node **head)
{
	t_node *curr_node;

	if (head == NULL || *head == NULL)
		return (NULL);
	curr_node = *head;
	while (curr_node->next != NULL)
		curr_node = curr_node->next;
	return (curr_node);
}

t_node *create_new_node(int pos, int val) 
{
	t_node *new_element;

	new_element = (t_node *)malloc(sizeof(t_node));
	if (new_element == NULL)
		return NULL;
	new_element->curr_pos = pos;
	new_element->index = -1;
	new_element->val = val;
	new_element->next = NULL;
	new_element->prev = NULL;
	
	return new_element;
}

void append_node(t_node **head, int pos, int val)
{
	t_node	*new_element;
	t_node	*current;

	new_element = create_new_node(pos,  val);
	if (new_element == NULL)
		return;
	if (*head == NULL) 
		*head = new_element;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_element;
		new_element->prev = current;
	}
}

t_node	*init_stack(char **args)
{
	t_node		*head;
	int			i;

	head = NULL;
	i = 0;

	check_spaces(args, &head);
	while (args[i] != NULL)
	{
		if (i == 0)
			head = create_new_node(i, ft_atoi_protected(args[i], &head));
		else
			append_node(&head, i, ft_atoi_protected(args[i], &head));
		i++;
	}
	check_dups(&head);
	update_pos(&head);
	return (head);
}

//Init stack when we have all arguments in quotes "4 3 2 -5"
t_node	*init_stack_qts(char *args)
{
	t_node		*head;
	int			i;
	char		**spl_args;
	

	spl_args = ft_split(args, ' ');
	head = NULL;
	i = 0;
	while (spl_args[i] != NULL)
	{
		if (i == 0)
			head = create_new_node(i, ft_atoi_protected(spl_args[i], &head));
		else
			append_node(&head, i, ft_atoi_protected(spl_args[i], &head));
		i++;
	}
	free_matrix(spl_args);
	check_dups(&head);
	update_pos(&head);
	return (head);
}


int	get_stack_size(t_node **head)
{
	int			i;
	t_node	*curr_node;

	curr_node = (*head);
	i = 0;
	while (curr_node != NULL)
	{
		i++;
		curr_node = curr_node->next;
	}
	return (i);
}

