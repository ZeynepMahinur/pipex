/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:37:42 by zarikan           #+#    #+#             */
/*   Updated: 2025/06/19 12:37:43 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int i, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
	{
		return ;
	}
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
	s[i] = '\0';
	return ;
}
