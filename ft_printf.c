/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:52:19 by fsariogl          #+#    #+#             */
/*   Updated: 2022/01/16 11:50:45 by fsariogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr, int count)
{
	if (nbr >= 10)
	{
		count = ft_putunbr(nbr / 10, count);
		count = ft_putunbr(nbr % 10, count);
	}
	else
		count = ft_putchar(nbr + '0', count);
	return (count);
}

int	ft_distribution(char c, int count, va_list argptr)
{
	if (c == 'c')
		count = ft_putchar(va_arg(argptr, int), count);
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(argptr, int), count);
	else if (c == 's')
		count = ft_putstr(va_arg(argptr, char *), count);
	else if (c == 'p')
		count = ft_adress(va_arg(argptr, void *), count);
	else if (c == 'u')
		count = ft_putunbr(va_arg(argptr, unsigned int), count);
	else if (c == 'x')
		count = ft_putnbr_base(va_arg(argptr, unsigned int), count,
				"0123456789abcdef");
	else if (c == 'X')
		count = ft_putnbr_base(va_arg(argptr, unsigned int), count,
				"0123456789ABCDEF");
	else
		count = ft_putchar(c, count);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	argptr;

	i = 0;
	count = 0;
	va_start(argptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			count = ft_distribution(str[i + 1], count, argptr);
			i++;
		}
		else if (str[i] != '%')
			count = ft_putchar(str[i], count);
		if (str[i] != '\0')
			i++;
	}
	va_end(argptr);
	return (count);
}
