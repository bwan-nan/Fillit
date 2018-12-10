/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:55:50 by cnotin            #+#    #+#             */
/*   Updated: 2018/11/22 12:36:57 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nb_word(char const *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	if (!(s))
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c || (s[i] != c && s[i - 1] == c))
			word++;
		i++;
	}
	return (word);
}
