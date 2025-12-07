/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/07 14:42:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_words(char **words, size_t filled)
{
	size_t	i;

	i = 0;
	while (i < filled)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	*next_word(char const **s, char c, size_t *len)
{
	size_t	i;

	while (**s && **s == c)
		(*s)++;
	i = 0;
	while ((*s)[i] && (*s)[i] != c)
		i++;
	*len = i;
	return ((char *)*s);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	words;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words)
	{
		s = next_word(&s, c, &len);
		result[i] = ft_substr(s, 0, len);
		if (!result[i++])
			return (free_words(result, i - 1), NULL);
		s += len;
	}
	result[words] = NULL;
	return (result);
}
