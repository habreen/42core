/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshamudh <hshamudh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/18 17:19:21 by hshamudh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static void	free_box(char **box, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(box[i]);
		i++;
	}
	free(box);
}

static char	*allocate_word(char *s, char c)
{
	int		len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, s, len);
	word[len] = '\0';
	return (word);
}

static char	**ft_split_main(char **box, char const *s, char c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (*ptr)
	{
		while (*ptr && *ptr == c)
			ptr++;
		if (*ptr)
		{
			box[i] = allocate_word(ptr, c);
			if (!box[i])
			{
				free_box(box, i);
				return (NULL);
			}
			i++;
		}
		while (*ptr && *ptr != c)
			ptr++;
	}
	box[i] = NULL;
	return (box);
}

char	**ft_split(char const *s, char c)
{
	char	**box;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	box = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!box)
		return (NULL);
	return (ft_split_main(box, s, c));
}
