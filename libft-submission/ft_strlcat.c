/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshamudh <hshamudh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/18 20:22:15 by hshamudh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	i = 0;
	while (i < n && dst[i])
		i++;
	dst_len = i;
	j = 0;
	while (src[j] && i + 1 < n)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < n)
		dst[i] = '\0';
	return (dst_len + ft_strlen(src));
}

// int main(void)
// {
//     char dest[10] = "Hi";
//     char *src = " there";

//     size_t len = ft_strlcat(dest, src, sizeof(dest));
//     printf("Result: %s\nLength: %zu\n", dest, len); // Output: "Hi there", 8
// }