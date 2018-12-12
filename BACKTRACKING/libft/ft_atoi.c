/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:53:09 by cnotin            #+#    #+#             */
/*   Updated: 2018/11/21 10:04:09 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	s;
	long	res;

	i = 0;
	res = 0;
	s = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (res > 2147483647 && s == 1)
			return (-1);
		if (res > 2147483648 && s == -1)
			return (0);
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * s);
}
