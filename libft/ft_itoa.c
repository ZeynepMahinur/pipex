/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:33:14 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/19 12:33:16 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	if (n == 0)
	{
		len++;
		n = n / 10;
	}
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*reverse(char *arr, int len)
{
	char	temp;
	int		i;

	i = 0;
	while (i < len)
	{
		temp = arr[i];
		arr[i] = arr[len];
		arr[len] = temp;
		len--;
		i++;
	}
	return (arr);
}

static int	if_zero_or_neg(long *nb, char *str, int len)
{
	int	i;

	i = 0;
	len = n_len(*nb);
	if (*nb == 0)
		str[i + 1] = '0';
	if (*nb < 0)
	{
		*nb = -*nb;
		str[len] = '-';
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;
	int		i;
	int		len;

	i = 0;
	nb = n;
	len = n_len(nb);
	str = malloc((sizeof(char)) * (len + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i = if_zero_or_neg(&nb, str, len);
	while (nb)
	{	
		str[i + 1] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	return (reverse(str, len));
}
