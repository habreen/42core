/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2026/01/22 21:12:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_and_join(int fd,char *stash)
{
    char *buffer;
    ssize_t bytes_read;
    
    buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
        return(NULL);
    bytes_read = 1;
    
    while (!ft_strchr(stash, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd,buffer,BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(buffer);
            return(NULL);
        }
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash,buffer);
    }
    free(buffer);
    return (stash);
}

static char *extract_line(char *stash)
{
    size_t i;
    
    if (!stash || stash[0] == '\0')
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    return (ft_substr(stash, 0, i));
}

