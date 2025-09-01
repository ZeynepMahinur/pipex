/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:31:48 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/19 12:31:49 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_item, size_t size)
{
	size_t	*ptr;
	size_t	total_size;

	total_size = num_item * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
