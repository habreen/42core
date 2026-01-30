/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2026/01/30 22:23:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_putnbr(int n)
{
	long	nb;
    int     count;

	nb = n;
    count = 0;
	if (nb < 0)
	{
		count = count + ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		count = count + ft_putnbr(nb / 10);
	}
	count = count + ft_putchar(nb % 10 + '0');
    return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
    unsigned int	nb;
    int             count;

    nb = n;
    count = 0;
    if (nb > 9)
    {
        count = count + ft_putnbr_unsigned(nb / 10);
    }
    count = count + ft_putchar(nb % 10 + '0');
    return (count);
}
