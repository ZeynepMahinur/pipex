/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:31:37 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/19 12:31:38 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	size_t				i;
	unsigned char		*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		p[i] = 0;
		i++;
	}
}
