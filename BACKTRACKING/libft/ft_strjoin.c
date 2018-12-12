/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:43:18 by cnotin            #+#    #+#             */
/*   Updated: 2018/11/20 11:38:11 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	unsigned int	len;

	if (!(s1) || !(s2))
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	return (new);
}
