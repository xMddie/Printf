/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:15:39 by mnau              #+#    #+#             */
/*   Updated: 2022/11/22 16:15:00 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(va_list param, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(param, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(param, char *)));
	else if (c == 'p')
		return (ft_puthex(va_arg(param, unsigned long), 0, 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(param, int)));
	else if (c == 'u')
		return (ft_putunsnbr(va_arg(param, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(param, unsigned int), 0, 0));
	else if (c == 'X')
		return (ft_puthex(va_arg(param, unsigned int), 1, 0));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	param;
	int		i;
	int		ret;

	va_start(param, str);
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ret += ft_check(param, str[i]);
		}
		else
			ret += ft_putchar(str[i]);
		i++;
	}
	return (ret);
}
