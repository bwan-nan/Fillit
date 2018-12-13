/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_sqrt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:52:06 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/12/13 17:24:42 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_next_sqrt(int nb)
{
	if (nb < 0)
		return (0);
	if (ft_sqrt(nb))
		return (ft_sqrt(nb));
	else
		while (ft_sqrt(nb) == 0)
			nb++;
	return (ft_sqrt(nb));
}
