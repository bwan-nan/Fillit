/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:15:57 by cnotin            #+#    #+#             */
/*   Updated: 2018/11/20 11:45:00 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;
	unsigned int	i;

	if (len == 0)
		return (b);
	i = 0;
	s = (unsigned char *)b;
	while (len--)
	{
		s[i] = ((unsigned char)c);
		s++;
	}
	return (b);
}
