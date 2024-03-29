/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:52:18 by fsariogl          #+#    #+#             */
/*   Updated: 2022/01/16 11:52:27 by fsariogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(int c, int count);
int	ft_putstr(const char *str, int count);
int	ft_putnbr(int n, int count);
int	ft_putnbr_base(unsigned long int nbr, int count, char *str);
int	ft_adress(void *str, int count);
int	ft_putunbr(unsigned int nbr, int count);
int	ft_distribution(char c, int count, va_list argptr);
int	ft_printf(const char *str, ...);

#endif
