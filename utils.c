/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <sliashko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:33:01 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/06 12:46:06 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_atoi(const char *str)
// {
// 	int	i;
// 	int	res;
// 	int	neg;

// 	i = 0;
// 	res = 0;
// 	neg = 1;
// 	while ((str[i] == ' ' || str[i] == '\n') && str[i] != '\0')
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			neg = -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		res = res * 10 + (str[i] - '0');
// 		i++;
// 	}
// 	return (res * neg);
// }

int	ft_atoi_protected(const char *str, t_node **head)
{
	int	i;
	long	res;
	int		neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((str[i] == ' ' || str[i] == '\n') && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if ((res * neg) > INT_MAX || (res * neg) < INT_MIN)
	{
		free_stack(head);
		ft_putstr_fd("ERROR\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (int)(res * neg);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
