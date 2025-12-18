/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshamudh <hshamudh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/15 20:40:29 by hshamudh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	fill_str(char *s, long n, size_t len)
{
	size_t	i;

	i = len - 1;
	if (n == 0)
	{
		s[0] = '0';
		return ;
	}
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nb;
	size_t	len;

	nb = n;
	len = num_len(nb);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	fill_str(s, nb, len);
	return (s);
}
