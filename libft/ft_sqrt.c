/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:42:12 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/01/11 13:42:13 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int i;
	int result;

	i = 1;
	result = i * i;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	if (i * i > nb)
		return (0);
	return (1);
}
