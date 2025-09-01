/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:38:12 by zarikan           #+#    #+#             */
/*   Updated: 2025/08/27 17:27:47 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	adjust_len(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	return (len1 + len2);
}

static void	s2_control(char *result, char const *s2, size_t *i, size_t *j)
{
	if (s2)
	{
		while (s2[*j])
		{
			result[*i + *j] = s2[*j];
			(*j)++;
		}
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;
	size_t	i;
	size_t	j;

	len = adjust_len(s1, s2);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
	}
	s2_control(result, s2, &i, &j);
	result[len] = '\0';
	return (result);
}
