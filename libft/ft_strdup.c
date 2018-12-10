/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:36:49 by cnotin            #+#    #+#             */
/*   Updated: 2018/12/01 18:24:58 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if (!(s2 = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	else
		s2 = ft_strcpy(s2, s1);
	return (s2);
}
