/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:53:52 by cnotin            #+#    #+#             */
/*   Updated: 2018/11/22 12:29:46 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_is_word(char const *s, int i, char c)
{
	if (i == 0 && s[i] != c)
		return (1);
	if (s[i] != c && s[i - 1] == c)
		return (1);
	return (0);
}

static	int		ft_count_word(char const *s, char c)
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

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**tab;

	i = 0;
	k = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * ft_count_word(s, c))))
		return (NULL);
	if (ft_count_word(s, c) == 0)
		return (tab);
	while (s[i])
	{
		j = 0;
		if (ft_is_word(s, i, c) && s[i] != c)
		{
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			tab[k++] = ft_strsub(s, i, j);
		}
		i++;
	}
	tab[k] = 0;
	return (tab);
}
