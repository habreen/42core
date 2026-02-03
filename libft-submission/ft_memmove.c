/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshamudh <hshamudh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/18 18:28:50 by hshamudh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s = (const unsigned char *)src;

	d = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	if (d > s)
		while (n--)
			d[n] = s[n];
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

// int main(void)
// {
//     char str1[] = "ABCDE";
//     char str2[] = "HelloWorld";

//     /* Test 1: normal copy (no overlap) */
//     ft_memmove(str2, str1, 5);
//     printf("No overlap: %s\n", str2);  // ABCDEWorld

//     /* Test 2: overlapping copy */
//     char str3[] = "12345";
//     ft_memmove(str3 + 1, str3, 4);
//     printf("Overlap: %s\n", str3);     // 11234

//     return (0);
// }