/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/07 14:27:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/* Allocates and returns an array of strings obtained by splitting `s`       */
/* using `c` as delimiter. The array ends with a NULL pointer.              */
/* ************************************************************************** */

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	free_split(char **arr, int last)
{
	while (last >= 0)
	{
		free(arr[last]);
		last--;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		i;
	int		k;
	int		start;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	out = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!out)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			out[k] = ft_substr(s, start, i - start);
			if (!out[k])
				return (free_split(out, k - 1), NULL);
			k++;
		}
		else
			i++;
	}
	out[k] = NULL;
	return (out);
}
