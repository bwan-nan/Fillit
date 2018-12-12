/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:57:06 by cnotin            #+#    #+#             */
/*   Updated: 2018/12/12 14:59:26 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_link(char *str, int j)
{
	int count;
	int i;


	i = 0;
	count = 0;
	while (i + j < 20 + j)
	{
		if (str[i + j] == '#')
		{
			if ((i + j + 1) < (20 + j) && str[i + j + 1] == '#')
				count++;
			if ((i + j - 1) >= (0 + j) && str[i + j - 1] == '#')
				count++;
			if ((i + j + 5) < (20 + j) && str[i + j + 5] == '#')
				count++;
			if ((i + j - 5) >= (0 + j) && str[i + j - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

static int		ft_validblock(char *str)
{
	static int 	i = 0;
	static int 	number_of_characters = 0;
	static int 	line_index = 0;
	static int 	hashtag = 0;

	while (str[i] == '.' || str[i] == '#' || str[i] == '\n')
	{
		if (str[i] == '.' || str[i] == '#')
			number_of_characters++;
		if (str[i] == '#')
			hashtag++;
		if (str[i] == '\n' && i != 0 && (i + 1) % 5 == 0)
			line_index++;
		if ((i + 1) % 21 == 0)
			if (str[i] != '\n')
				return (0);
		i++;
	}
	if (number_of_characters % 16 != 0)
		return (0);
	if (hashtag % 4 != 0 || hashtag == 0)
		return (0);
	if ((line_index + 1) % 5 != 0)
		return (0);
	return (((i + 1) % 21 != 0) ? 0 : 1);
}

int				ft_check_file(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i + j] != '\0')
	{
		if (!(ft_validblock(str) && ft_check_link(str, j)))
			return (0);
		i = 19;
		if (str[i + j] == '\n' && str[i + j + 1] == '\0')
			return (1);
		if (str[i + j] == '\n' && str[i + j + 1] == '\n'
				&& (str[i + j + 2] == '.' || str[i + j + 2] == '#'))
			j += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}
