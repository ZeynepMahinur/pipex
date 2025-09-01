/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:34:22 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/19 12:34:23 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_forward(char *d, const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

static void	copy_backward(char *d, const char *s, size_t n)
{
	while (n > 0)
	{
		n--;
		d[n] = s[n];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
	{
		return (NULL);
	}
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
		copy_forward((char *)d, (const char *)s, n);
	else
		copy_backward((char *)d, (const char *)s, n);
	return (dest);
}
