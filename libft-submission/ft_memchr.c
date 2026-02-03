/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshamudh <hshamudh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/18 20:18:26 by hshamudh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		value;
	size_t				i;

	ptr = (const unsigned char *)s;
	value = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == value)
			return ((void *)&ptr[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
//     unsigned char data[] = {10, 20, 30, 40, 50};
//     unsigned char *p;

//     p = ft_memchr(data, 30, 5);

//     if (p)
//         printf("Found: %u\n", *p); // Output: 30
//     else
//         printf("Not found\n");

//     return 0;
// }