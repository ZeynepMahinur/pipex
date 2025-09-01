/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:38:21 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/19 12:38:22 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	str1;
	size_t	str2;
	size_t	i;

	str1 = 0;
	str2 = 0;
	i = 0;
	while (dest[str1] != '\0' && str1 < size)
	{
		str1++;
	}
	while (src[str2] != '\0')
	{
		str2++;
	}
	if (size <= str1)
		return (size + str2);
	while (src[i] != '\0' && (str1 + i < size - 1))
	{
		dest[str1 + i] = src[i];
		i++;
	}
	dest[str1 + i] = '\0';
	return (str1 + str2);
}
