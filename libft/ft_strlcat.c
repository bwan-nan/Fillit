/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:14:46 by cnotin            #+#    #+#             */
/*   Updated: 2018/11/16 00:34:59 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[j] && j < dstsize)
		j++;
	while (src[i] && (i + j + 1) < dstsize)
	{
		dst[j + i] = src[i];
		i++;
	}
	if (i + j < dstsize)
		dst[j + i] = '\0';
	return (j + ft_strlen(src));
}
