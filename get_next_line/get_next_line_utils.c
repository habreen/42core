/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2026/01/18 21:47:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t i;
    i=0;
    if(!s)
        return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}

void ft_bzero(void *s,size_t n)
{
    size_t i;
    char *ptr;
    
    ptr = (char *)s;
    i= 0;
    
    while (i < n)
    {
        ptr[i] = 0;
        i++;
    }
}

void *ft_calloc(size_t count, size_t size)
{
    void *ptr;
    
    ptr = malloc(count * size);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, count * size);
    return (ptr);
}

char *ft_strdup(const char *s1)
{
    char *dup;
    size_t len;
    size_t i;

    len = ft_strlen(s1);
    dup = (char *)malloc((len + 1) * sizeof(char));
    if (!dup)
        return (NULL);
    i = 0;
    while (i < len)
    {
        dup[i] = s1[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char *ft_strchr(const char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (NULL);
}

char *ft_strjoin(char *s1, char *s2)
{
    size_t len1;
    size_t len2;
    size_t i;
    size_t j;
    char *joined;

    if (!s1 && !s2)
        return (NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    joined = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (!joined)
        return (NULL);
    i = 0;
    j = 0;
    while (i < len1)
    {
        joined[i] = s1[i];
        i++;
    }
    while (j < len2)
    {
        joined[i + j] = s2[j];
        j++;
    }
    joined[i + j] = '\0';
    free(s1);
    return (joined);
}

char *ft_substr(char *s, unsigned int start, size_t len)
{
    char *sub;
    size_t i;
    size_t s_len;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
        return (ft_strdup(""));
    if (len > s_len - start)
        len = s_len - start;
    sub = (char *)malloc((len + 1) * sizeof(char));
    if (!sub)
        return (NULL);
    i = 0;
    while (i < len && s[start + i] != '\0')
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}

