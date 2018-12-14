/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:21:09 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/12/14 11:33:01 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdupendl(const char *s1)
{
	char	*s2;

	if (!(s2 = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s1) + 2))))
		return (NULL);
	else
		s2 = ft_strcpy(s2, s1);
	s2[ft_strlen(s1)] = '\n';
	s2[ft_strlen(s1) + 1] = '\0';
	return (s2);
}
