/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:29:28 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/22 19:30:09 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	count += write (1, "0x", 2);
	count += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
