/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2025/12/07 13:21:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_gen_len(long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nb;
	size_t	len;

	nb = n;
	len = ft_gen_len(nb);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (nb == 0)
	{
		s[0] = '0';
		return (s);
	}
	len--;
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		s[len] = (nb % 10) + '0';
		nb = nb / 10;
		nb--;
	}
	return (s);
}
