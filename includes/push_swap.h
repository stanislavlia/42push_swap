/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:17:52 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/03 14:59:49 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct node
{
	int	curr_pos;
	int	index;
	int	val;
	struct node *next;
	struct node *prev;
	int	cost;
	int	is_cheapest;
}			t_node;

typedef struct push_swap
{
	t_node *stack_a;
	t_node *stack_b;
	
}			t_push_swap;

//Utils
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

//Linkedlist utils
t_node	*init_stack(char **args);


#endif
