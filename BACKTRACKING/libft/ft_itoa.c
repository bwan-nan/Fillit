/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:56:41 by cnotin            #+#    #+#             */
/*   Updated: 2018/11/21 11:05:10 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	nb_len(long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	long	number;
	int		len;
	char	*str;
	char	sign;

	number = n;
	sign = (number < 0 ? 1 : 0);
	len = nb_len(number);
	str = ft_strnew(len + sign);
	if (str == NULL)
		return (NULL);
	if (sign)
	{
		number = -number;
		str[0] = '-';
	}
	while (len > 0)
	{
		str[len + sign - 1] = (number % 10) + '0';
		len--;
		number = number / 10;
	}
	return (str);
}
