/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:13:40 by mnau              #+#    #+#             */
/*   Updated: 2022/11/22 11:29:00 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar('-');
			count++;
		}
		if (n > 9)
		{
			count += ft_putnbr(n / 10);
			count += ft_putnbr(n % 10);
		}
		else
		{
			ft_putchar('0' + n);
			count++;
		}
	}
	return (count);
}

int	ft_putunsnbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putunsnbr(n / 10);
		count += ft_putunsnbr(n % 10);
	}
	else
	{
		ft_putchar('0' + n);
		count++;
	}
	return (count);
}

int	ft_puthex(unsigned long n, int upper, int address)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (upper)
		base = "0123456789ABCDEF";
	if (address)
	{
		ft_putstr("0x");
		address -= address;
		count += 2;
	}
	if (n >= 16)
	{
		count += ft_puthex(n / 16, upper, 0);
		count += ft_puthex(n % 16, upper, 0);
	}
	if (n < 16)
		count += ft_putchar(base[n]);
	return (count);
}
