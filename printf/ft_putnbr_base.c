/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:13:09 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/22 19:28:37 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long number, const char *base)
{
	int				count;
	unsigned long	len;

	count = 0;
	len = 0;
	while (base[len])
		len++;
	if (number >= len)
	{
		count += ft_putnbr_base(number / len, base);
	}
	count += write(1, &base[number % len], 1);
	return (count);
}
