/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:16:38 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/22 19:29:04 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h> 

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_base(unsigned long number, const char *base);
int	ft_putnbr(int number);
int	ft_percent(void);
int	ft_putptr(void *ptr);
int	ft_printf(const char *f, ...);

#endif
