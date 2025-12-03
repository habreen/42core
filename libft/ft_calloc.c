/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/03 18:25:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    void *ptr;
    size_t total_size;
    
    if(count != 0 && total_size / count != size)
        return(NULL);

    ptr = malloc(count * size);
    if (ptr == 0)
        return(NULL);
    
    ft_bzero(ptr,total_size);
    return(ptr);
}