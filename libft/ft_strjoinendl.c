/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinendl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:13:50 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/12/14 11:34:28 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinendl(char const *s1, char const *s2)
{
	char			*new;
	unsigned int	len;

	if (!(s1) || !(s2))
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * len + 2)))
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	new[len] = '\n';
	new[len + 1] = '\0';
	return (new);
}
