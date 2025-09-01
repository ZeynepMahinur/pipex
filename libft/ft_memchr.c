/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:33:32 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/19 12:33:34 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*s;
	size_t				i;

	i = 0;
	s = str;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (0);
}
