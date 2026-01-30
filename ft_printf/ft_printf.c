/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:52:15 by hshamudh          #+#    #+#             */
/*   Updated: 2026/01/30 20:36:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int handle_format(char c,va_list args)
{
    if (c == 'c')
        return(ft_putchar(va_arg(args,int)));
    if (c == 's')
        return(ft_putstr(va_arg(args,char *)));
    if (c == 'd' || c == 'i')
        return(ft_putnbr(va_arg(args,int)));
    if (c == 'u')
        return(ft_putnbr_unsigned(va_arg(args,unsigned int)));
    if (c == 'x' || c == 'X')
        return(ft_puthex(va_arg(args,unsigned int),c));
    if (c == 'p')
        ft_putstr("0x");
        return(2+ ft_puthex(va_arg(args,unsigned long),c));
    if (c == '%')
        return(ft_putchar('%'));
    return(0);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int count;

    i = 0;
    count = 0;
    va_start(args,format);
    
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            count += handle_format(format[i + 1],args);
            i++;
        }
        else
            count += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return(count);
}
