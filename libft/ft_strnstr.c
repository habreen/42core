/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/02 15:32:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t  i;
    size_t  little_len;

    little_len = ft_strlen(little);
    
    if (little_len == 0)
        return ((char *)big);

    i = 0;
    while (big[i] && little_len <= len - i)
    {
        if (!ft_strncmp(big + i, little, little_len))
            return ((char *)big + i);
        i++;
    }
    
    return (0);
}