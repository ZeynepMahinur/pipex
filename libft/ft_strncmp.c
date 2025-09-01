/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:38:45 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/19 12:38:46 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	str1;
	unsigned char	str2;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		str1 = (unsigned char)s1[i];
		str2 = (unsigned char)s2[i];
		if (str1 != str2)
			return (str1 - str2);
		if (str1 == str2 && str1 == '\0')
			return (0);
		i++;
	}
	return (0);
}
