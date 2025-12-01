/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshamudh <hshamudh@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/01 13:19:56 by hshamudh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i; /*  index for dst */
	size_t j; /* index for src */
	/*  Find the end of dst */
	i = 0;
	while (i < n && dst[i])
		i++;
	j = 0;
	/* Append src to dst */
	while (src[j] && i + 1 < n)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	/*  Null-terminate if there is room */
	if (i < n)
		dst[i] = '\0';
	/* Return total length we tried to create: original dst length
		+ src length */
	return (i + ft_strlen(src + j));
}
