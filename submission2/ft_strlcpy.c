/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshamudh <hshamudh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/18 20:15:44 by hshamudh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	if (n == 0)
		return (len);
	i = 0;
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

// int main(void)
// {
//     char src[] = "Hello, World!";
//     char dest[6]; // small buffer

//     size_t len = ft_strlcpy(dest, src, sizeof(dest));

//     printf("Copied: %s\n", dest);   // Output: "Hello"
//     printf("Source length: %zu\n", len); // Output: 13

//     return 0;
// }