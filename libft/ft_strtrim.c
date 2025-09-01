/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:39:17 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/19 12:39:18 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	first_char(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
	}
	return (i);
}

static size_t	last_char(char const *s1, char const *set)
{
	size_t	len;

	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len - 1]))
	{
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	last;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = first_char(s1, set);
	last = last_char(s1, set);
	if (start >= last)
	{
		result = malloc(1);
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	result = ((char *)malloc(last - start + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (start < last)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}
