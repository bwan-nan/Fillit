/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:14:38 by cnotin            #+#    #+#             */
/*   Updated: 2018/11/22 12:57:31 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0' && s2[i] != '\0') && (i < n))
		i++;
	if (i == n)
		return (((unsigned char)s1[i - 1]) - ((unsigned char)s2[i - 1]));
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
