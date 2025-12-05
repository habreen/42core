/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/05 14:48:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int isinset(char c, const char *set)
{
    size_t i;

    i = 0;
    while(set && set[i])
    {
        if (set[i] == c)
            return(1);
        i++;
    }
    return(0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    size_t end;

    if (!s1)
        return(NULL);
    if (!set || *set == '\0')
        return(ft_strdup(s1));
    start = 0;
    while (s1[start] && isinset(s1[start], set))
        start++;
    end = ft_strlen(s1);
    while (end > start && isinset(s1[end-1], set))
        end--;
    return(ft_substr(s1, start, end - start));
}