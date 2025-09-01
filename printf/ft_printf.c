/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:53:27 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/21 19:02:59 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formats(char c, va_list args)
{
	if (c == '%')
		return (ft_percent());
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	return (0);
}

int	ft_printf(const char *f, ...)
{
	int		i;
	int		c;
	va_list	args;

	va_start (args, f);
	i = 0;
	c = 0;
	while (f[i])
	{
		if (f[i] == '%')
		{
			i++;
			c += formats(f[i], args);
		}
		else
			c += ft_putchar(f[i]);
		i++;
	}
	va_end(args);
	return (c);
}
