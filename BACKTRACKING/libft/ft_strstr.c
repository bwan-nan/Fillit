/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 21:53:51 by cnotin            #+#    #+#             */
/*   Updated: 2018/11/14 14:31:19 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*str;

	str = (char *)haystack;
	if (*needle == '\0')
		return (str);
	while (*str != '\0')
	{
		i = 0;
		while (needle[i] == str[i] && needle[i] != '\0')
			i++;
		if (needle[i] == '\0')
			return (str);
		str++;
	}
	return (0);
}
