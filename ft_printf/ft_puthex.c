/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthex                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2026/01/30 22:23:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthex(unsigned long n, char format)
{
    char *base;
    int count;

    if(format == 'x')
        base = "0123456789abcdef";
    else
         base = "0123456789ABCDEF";
    count = 0;
    if(n>=16)
        count = count + ft_puthex(n/16,format);
    count = count + ft_putchar(base[n%16]);
    return (count);
}
