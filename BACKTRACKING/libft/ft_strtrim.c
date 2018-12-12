/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:00:20 by cnotin            #+#    #+#             */
/*   Updated: 2018/11/20 11:54:03 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*new;
	size_t			len;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!(s))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	len = ft_strlen(s);
	if (!s[len])
		len--;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
	{
		len--;
		j++;
	}
	if (i == j && i == ft_strlen(s))
		new = ft_strsub(s, i, 0);
	else
		new = ft_strsub(s, i, ft_strlen(s) - i - j);
	return (new);
}
