/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:47:10 by sliashko          #+#    #+#             */
/*   Updated: 2024/01/06 15:47:11 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_wordcount(char const *str, char c)
{
	int	i;
	int	n_words;

	i = 0;
	n_words = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
		{
			i++;
		}
		if (str[i] == '\0')
			return (n_words);
		n_words++;
		while (str[i] != c && str[i] != '\0')
		{
			i++;
		}
	}
	return (n_words);
}

unsigned long	ft_strlcpy(char *dest, char *src, unsigned long size)
{
	unsigned long	i;

	i = 0;
	if (size > 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	**ft_init_array(int n_words)
{
	char	**array;

	array = (char **) malloc(sizeof(char *) * (n_words + 1));
	return (array);
}

static char	*ft_extract_word(const char *s, int *i, char c)
{
	int		start;
	char	*word;

	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	if (*i > start)
	{
		word = malloc(*i - start + 1);
		if (word)
		{
			ft_strlcpy(word, (char *)s + start, *i - start + 1);
		}
		return (word);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**array;

	i = 0;
	j = 0;
	array = ft_init_array(ft_wordcount(s, c));
	if (!array)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			array[j] = ft_extract_word(s, &i, c);
			if (!array[j])
				return (NULL);
			j++;
		}
	}
	array[j] = NULL;
	return (array);
}
