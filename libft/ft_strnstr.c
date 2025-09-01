/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:38:56 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/19 12:38:56 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*find)
		return ((char *)s);
	i = 0;
	while (s[i] != '\0' && i < len)
	{
		j = 0;
		while (find[j] && s[i + j] && s[i + j] == find[j] && (i + j) < len)
		{
			j++;
		}
		if (!find[j])
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
