/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:44:47 by fsariogl          #+#    #+#             */
/*   Updated: 2022/01/15 19:57:25 by fsariogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putstr(const char *str, int count)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		count = ft_putchar(str[i], count);
		i++;
	}
	return (count);
}

int	ft_putnbr(int n, int count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (count + 11);
	}
	if (n < 0)
	{
		count = ft_putchar('-', count);
		n = n * -1;
	}
	if (n > 9)
	{
		count = ft_putnbr(n / 10, count);
		count = ft_putnbr(n % 10, count);
	}
	else
		count = ft_putchar(n + '0', count);
	return (count);
}

int	ft_putnbr_base(unsigned long int nbr, int count, char *str)
{
	if (nbr >= 16)
	{
		count = ft_putnbr_base(nbr / 16, count, str);
		count = ft_putnbr_base(nbr % 16, count, str);
	}
	else
		count = ft_putchar(str[nbr], count);
	return (count);
}

int	ft_adress(void *str, int count)
{
	unsigned long int	nbr;

	if (!str)
		count = ft_putstr("0x0", count);
	else
	{
		nbr = (unsigned long int)str;
		count = ft_putstr("0x", count);
		count = ft_putnbr_base(nbr, count, "0123456789abcdef");
	}
	return (count);
}
