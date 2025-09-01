/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:31:03 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/19 14:26:11 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	my_isspace(const char *str, int *i)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
	{
		(*i)++;
	}
	return (0);
}

static int	negative_sign(const char *str, int *i, int *sign)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			*sign = -1;
			(*i)++;
		}
		else if (str[*i] == '+')
		{
			(*i)++;
		}
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	my_isspace(str, &i);
	negative_sign(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
